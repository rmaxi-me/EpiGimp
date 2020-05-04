#include <cmath>
#include <array>
#include <functional>
#include <SFML/Graphics.hpp>

using Renderer = std::function<void(const sf::Vector2f &, sf::Image &)>;

static auto drawCircle = [](const sf::Vector2f &pt, sf::Image &img) -> void
{
    constexpr auto RADIUS = 10.0f;
    const auto COLOR = sf::Color::Red; // sfml is c++98 so not constexpr :( // tmp anyway

    for (auto y = -RADIUS; y != RADIUS; y++)
        for (auto x = -RADIUS; x != RADIUS; x++)
            if (pt.x + x >= 0 && pt.x + x <= img.getSize().x
                && pt.y + y >= 0 && pt.y + y <= img.getSize().y
                && std::sqrt(std::pow(x, 2) + std::pow(y, 2)) <= RADIUS)
            // if the point is in the circle and the image
                img.setPixel(pt.x + x, pt.y + y, COLOR);
};

static auto drawSquare = [](const sf::Vector2f &pt, sf::Image &img) -> void
{
    constexpr auto RADIUS = 10.0f;
    const auto COLOR = sf::Color::Red;

    for (auto y = -RADIUS; y != RADIUS; y++)
        for (auto x = -RADIUS; x != RADIUS; x++)
            if (pt.x + x >= 0 && pt.x + x <= img.getSize().x
                && pt.y + y >= 0 && pt.y + y <= img.getSize().y)
            // if the point is in the image
                img.setPixel(pt.x + x, pt.y + y, COLOR);
};

auto main() -> int
{
    constexpr auto WINDOW_W = 1080; constexpr auto WINDOW_H = 720;

    sf::RenderWindow w{ { WINDOW_W, WINDOW_H },
        "Experimental Gimp Application",
        sf::Style::Close | sf::Style::Resize };

    // set the window properties
    w.setActive(true); w.setVisible(true);

    constexpr auto FPS_LIMIT = 60;
    w.setFramerateLimit(FPS_LIMIT); w.setVerticalSyncEnabled(true);

    w.setKeyRepeatEnabled(true);

    constexpr auto CANVAS_W = 1080; constexpr auto CANVAS_H = 720;
    const auto DEFAULT_CANVAS_COLOR = sf::Color::White;

    sf::Image drawing; drawing.create(CANVAS_W, CANVAS_H, DEFAULT_CANVAS_COLOR);
    sf::Texture canvasTexture; canvasTexture.loadFromImage(drawing);

    sf::RectangleShape canvas{ { CANVAS_W, CANVAS_H } }; canvas.setTexture(&canvasTexture);
    // canvas object will not be modifed anymore // only the texture is updated

    constexpr auto SCALE_MOVE = 10.0f; // further to zero => faster movement
    constexpr auto SCALE_ZOOM = 50.0f; // closer to zero => faster zoom

    float zoom = 1.0f;
    // keep the zoom, used when window is resized

    bool mouseGrabbed = false;
    // is the mouse button currently pressed

    sf::Vector2f dragPoint;
    // last position where the mouse button pressed

    sf::Cursor c;
    // keep the cursor in the same scope as the window because
    // the cursor must not be destroyed while in use by the window.

    const std::array<Renderer, 2ul> renderers = { drawCircle, drawSquare };
    auto actifRenderer = 0;

    while (w.isOpen()) {

        sf::Event e{};
        while (w.pollEvent(e)) {
            if (e.type == sf::Event::Closed)
                w.close();

            else if (e.type == sf::Event::Resized) {
                sf::View view{ w.getView() };
                view.setSize({ static_cast<float>(e.size.width), static_cast<float>(e.size.height) });
                view.zoom(zoom);
                w.setView(view);

            } else if (e.type == sf::Event::KeyPressed) {

                bool updateView = false;
                sf::Vector2f offset{ 0, 0 };
                switch (e.key.code) {
                    case sf::Keyboard::Up:      offset = { +0, -1 }; updateView = true; break;
                    case sf::Keyboard::Down:    offset = { +0, +1 }; updateView = true; break;
                    case sf::Keyboard::Right:   offset = { +1, +0 }; updateView = true; break;
                    case sf::Keyboard::Left:    offset = { -1, +0 }; updateView = true; break;
                    case sf::Keyboard::F1:      actifRenderer--; break;
                    case sf::Keyboard::F2:      actifRenderer++; break;
                    default: break;
                }
                if (updateView) {
                    sf::View view{ w.getView() };
                    view.move(offset.x * SCALE_MOVE, offset.y * SCALE_MOVE);
                    w.setView(view);
                }

            } else if (e.type == sf::Event::MouseWheelScrolled) {
                sf::View view{ w.getView() };
                zoom *= 1 - e.mouseWheelScroll.delta / SCALE_ZOOM;
                view.zoom(1 - e.mouseWheelScroll.delta / SCALE_ZOOM);
                w.setView(view);

            } else if (e.type == sf::Event::MouseButtonPressed) {

                if (e.mouseButton.button == sf::Mouse::Right) {
                    mouseGrabbed = true;
                    w.setMouseCursorGrabbed(true);
                    dragPoint = w.mapPixelToCoords({ e.mouseButton.x, e.mouseButton.y });

                    c.loadFromSystem(sf::Cursor::Hand);
                    w.setMouseCursor(c);
                } else {

                    const auto px = w.mapPixelToCoords({ e.mouseButton.x, e.mouseButton.y });
                    if (canvas.getLocalBounds().contains(px.x, px.y)) {
                        renderers.at(actifRenderer % renderers.size())(px, drawing);
                        canvasTexture.update(drawing);
                    }
                }

            } else if (e.type == sf::Event::MouseButtonReleased) {

                if (e.mouseButton.button == sf::Mouse::Right) {
                    mouseGrabbed = false;
                    w.setMouseCursorGrabbed(false);

                    c.loadFromSystem(sf::Cursor::Arrow);
                    w.setMouseCursor(c);
                }

            } else if (e.type == sf::Event::MouseMoved) {

                if (mouseGrabbed) {
                    sf::View view{ w.getView() };
                    const auto dropPoint = dragPoint - w.mapPixelToCoords({ e.mouseMove.x, e.mouseMove.y });
                    view.move(dropPoint);
                    w.setView(view);
                }

            }

        }

        w.clear();
        w.draw(canvas);
        w.display();

    }

    return 0;
}
