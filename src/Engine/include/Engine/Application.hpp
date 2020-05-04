/*
** EpiGimp Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#pragma once

#include <cstdint>
#include <memory>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

namespace usa {

namespace Engine {

class Application {
public:
    Application(int ac, char **av);
    virtual ~Application() = default;

    auto start(const std::string_view &title) -> void;
    auto drawFps() -> void;

    virtual auto processEvent(const sf::Event &event) -> void;

    virtual auto init() -> void = 0;
    virtual auto deinit() -> void = 0;
    virtual auto tick(float deltaTime) -> void = 0;
    virtual auto draw() -> void = 0;

    static sf::Font DefaultFont;

protected:
    sf::RenderWindow m_window;

    std::uint32_t m_fps{0};
    sf::Time m_deltaTime{};

private:
    sf::Text m_textFPS{};

};

} // namespace Engine

} // namespace usa
