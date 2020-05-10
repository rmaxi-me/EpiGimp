/*
** EpiGimp Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include <iostream> // TODO: Remove
#include "SceneCanvas.hpp"

SceneCanvas::SceneCanvas(unsigned int width, unsigned int height) : m_width{width}, m_height{height}
{
    m_canvasImage.create(m_width, m_height, sf::Color::White);
}

SceneCanvas::SceneCanvas(const std::string_view &file) : m_width{0}, m_height{0}
{
    const std::string strFile{file};

    if (!m_canvasImage.loadFromFile(strFile)) { throw std::runtime_error("Could not load image " + strFile); }

    m_width = m_canvasImage.getSize().x;
    m_height = m_canvasImage.getSize().y;
}

bool SceneCanvas::onCreate(usa::Engine::Application &)
{
    m_canvasTexture.create(m_width, m_height);
    m_canvasTexture.setSmooth(false);

    m_rect.setPosition(0, 0);
    m_rect.setSize({static_cast<float>(m_width), static_cast<float>(m_height)});
    m_rect.setTexture(&m_canvasTexture);
    return true;
}

void SceneCanvas::onEvent(sf::RenderWindow &window, const sf::Event &event)
{
    switch (event.type) {
    case sf::Event::EventType::MouseButtonPressed:
        if (event.mouseButton.button == sf::Mouse::Right) {
            m_mouseGrabbed = true;
            m_grabPoint = window.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});
            window.setMouseCursorGrabbed(true);
        }
        break;
    case sf::Event::EventType::MouseButtonReleased:
        if (event.mouseButton.button == sf::Mouse::Right) {
            m_mouseGrabbed = false;
            window.setMouseCursorGrabbed(false);
        }
        break;
    case sf::Event::EventType::MouseMoved:
        if (m_mouseGrabbed) {
            sf::View view = window.getView();
            const auto dropDelta = m_grabPoint - window.mapPixelToCoords({event.mouseMove.x, event.mouseMove.y});
            view.move(dropDelta);
            window.setView(view);
        }
        break;
    case sf::Event::EventType::MouseWheelScrolled: updateView(window, {}, -event.mouseWheelScroll.delta); break;
    default: break;
    }
}

void SceneCanvas::onTick(sf::RenderWindow &window, float deltaTime)
{
    m_deltaTime = deltaTime;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) updateView(window, {0.f, -1.f});
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) updateView(window, {-1.f, 0.f});
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) updateView(window, {0.f, 1.f});
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) updateView(window, {1.f, 0.f});

    /*
     * Insert image manipulations here
     */

    m_canvasTexture.update(m_canvasImage);
}

void SceneCanvas::onDraw(sf::RenderWindow &window) const { window.draw(m_rect); }

auto SceneCanvas::updateView(sf::RenderWindow &window, sf::Vector2f delta, const float zoomDelta) const -> void
{
    auto view = window.getView();

    delta.x *= MOVE_SPEED * m_deltaTime;
    delta.y *= MOVE_SPEED * m_deltaTime;
    view.move(delta);

    if (zoomDelta > 0)
        view.zoom(1.1f);
    else if (zoomDelta < 0)
        view.zoom(0.9f);

    window.setView(view);
}
