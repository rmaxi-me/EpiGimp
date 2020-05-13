/*
** EpiGimp Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include <imgui.h>
#include <imgui-SFML.h>

#include <algorithm>

#include "SceneCanvas.hpp"
#include "CanvasMenus.hpp"

SceneCanvas::SceneCanvas(unsigned int width, unsigned int height) { m_layers.emplace_back(width, height); }

SceneCanvas::SceneCanvas(const std::vector<std::string_view> &files)
{
    for (const auto &file : files) m_layers.emplace_back(file);
}

bool SceneCanvas::onCreate(Engine::Application &) { return true; }

void SceneCanvas::onEvent(const sf::Event &event)
{
    switch (event.type) {
    case sf::Event::EventType::MouseButtonPressed:
        if (event.mouseButton.button == sf::Mouse::Right) {
            m_mouseGrabbed = true;
            m_grabPoint = m_window->mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});

            m_cursor.loadFromSystem(sf::Cursor::Hand);
            m_window->setMouseCursor(m_cursor);
            m_window->setMouseCursorGrabbed(true);
        }
        break;
    case sf::Event::EventType::MouseButtonReleased:
        if (event.mouseButton.button == sf::Mouse::Right) {
            m_mouseGrabbed = false;

            m_cursor.loadFromSystem(sf::Cursor::Arrow);
            m_window->setMouseCursor(m_cursor);
            m_window->setMouseCursorGrabbed(false);
        }
        break;
    case sf::Event::EventType::MouseMoved:
        if (m_mouseGrabbed) {
            sf::View view = m_window->getView();
            const auto dropDelta = m_grabPoint - m_window->mapPixelToCoords({event.mouseMove.x, event.mouseMove.y});
            view.move(dropDelta);
            m_window->setView(view);
        }
        break;
    case sf::Event::EventType::MouseWheelScrolled: updateView({}, -event.mouseWheelScroll.delta); break;
    default: break;
    }
}

void SceneCanvas::onTick(float deltaTime)
{
    m_deltaTime = deltaTime;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) updateView({0.f, -1.f});
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) updateView({-1.f, 0.f});
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) updateView({0.f, 1.f});
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) updateView({1.f, 0.f});

    /*
     * Insert image manipulations here
     */

    for (auto &layer : m_layers) {
        layer.texture.update(layer.image);

        // Performance cost: the texture ID stays the same but the cache ID changes.
        // Without this line, only the last texture is visible, the others appear blank.
        // TODO: One thing we could do is to only update the texture once a change has been made.
        layer.sprite.setTexture(layer.texture);
    }
}

auto SceneCanvas::updateView(sf::Vector2f delta, const float zoomDelta) const -> void
{
    auto view = m_window->getView();

    delta.x *= MOVE_SPEED * m_deltaTime;
    delta.y *= MOVE_SPEED * m_deltaTime;
    view.move(delta);

    if (zoomDelta > 0)
        view.zoom(1.1f);
    else if (zoomDelta < 0)
        view.zoom(0.9f);

    m_window->setView(view);
}

void SceneCanvas::onDraw()
{
    for (const auto &layer : m_layers) {
        if (!layer.hidden) m_window->draw(layer.sprite);
    }

    menu.drawMainMenuBar();
    drawLayerWindow();
}

auto SceneCanvas::drawLayerWindow() -> void
{
    ImGui::SetNextWindowSize({0, 0});
    ImGui::Begin("Layers");
    {
        std::size_t index = m_layers.size();
        for (auto layer = m_layers.rbegin(); layer != m_layers.rend(); ++layer) {
            ImGui::PushID(std::addressof(*layer));
            {
                ImGui::Text("Layer %ld", index);
                ImGui::BeginGroup();
                {
                    if (ImGui::Button("Up", {50, 0})) swapLayers(layer, -1);
                    if (ImGui::Button("Down", {50, 0})) swapLayers(layer, 1);
                    if (ImGui::Button(layer->hidden ? "Show" : "Hide", {50, 0})) layer->hidden = !layer->hidden;
                }
                ImGui::EndGroup();
                ImGui::SameLine();
                ImGui::Image(layer->texture, {66.7f, 66.7f / layer->ratio});

                ImGui::Spacing();
                ImGui::Separator();
                ImGui::Spacing();
            }
            ImGui::PopID();
        }

        if (ImGui::Button("Squash and export")) squash().saveToFile("export.png");
    }
    ImGui::End();
}

auto SceneCanvas::swapLayers(decltype(m_layers)::reverse_iterator &current, int offset) -> void
{
    if (offset == -1) {
        // Move UP
        if (current == m_layers.rbegin()) return;
    } else if (offset == 1) {
        // Move DOWN
        if (current + 1 == m_layers.rend()) return;
    }
    std::iter_swap(current, current + offset);
}

auto SceneCanvas::getLargestImageSize() const -> sf::Vector2u
{
    sf::Vector2u max{};

    for (const auto &layer : m_layers) {
        max = std::max(max, layer.image.getSize(), [](const sf::Vector2u &a, const sf::Vector2u &b) {
            return a.x * a.y < b.x * b.y;
        });
    }
    return max;
}

auto SceneCanvas::squash() const -> sf::Image
{
    sf::Image image{};
    const auto largest = getLargestImageSize();
    image.create(largest.x, largest.y, sf::Color::Transparent);

    for (const auto &layer : m_layers) {
        const auto &pos = layer.sprite.getPosition();
        image.copy(layer.image, static_cast<unsigned int>(pos.x), static_cast<unsigned int>(pos.y), sf::IntRect{}, true);
    }
    return image;
}

SceneCanvas::Layer::Layer(unsigned int width, unsigned int height, sf::Color color)
{
    image.create(width, height, color);
    init();
}

SceneCanvas::Layer::Layer(const std::string_view &file)
{
    if (!image.loadFromFile(std::string(file))) throw std::runtime_error("Failed to load image");
    init();
}

auto SceneCanvas::Layer::init() -> void
{
    ratio = static_cast<float>(image.getSize().x) / static_cast<float>(image.getSize().y);
    texture.loadFromImage(image);

    sprite.setPosition(0.f, 0.f);
    sprite.setTexture(texture);
}
