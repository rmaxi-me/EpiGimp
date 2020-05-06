/*
** EpiGimp Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#pragma once

#include <cstdint>
#include <memory>
#include <iostream>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

#include "Engine/Settings/Settings.hpp"
#include "Scene.hpp"

namespace usa {

namespace Engine {

class Application {
public:
    Application(int ac, char **av);
    virtual ~Application();

    auto start(const std::string_view &title) -> void;
    auto drawFps() -> void;

    template<typename S, typename... Args>
    auto createScene(Args &&... args) -> bool
    {
        m_scene = std::make_unique<S>(std::forward<Args>(args)...);

        if (!m_scene->onCreate()) {
            std::cerr << "Failed to create scene\n";
            m_scene.reset(nullptr);
            return false;
        }
        return true;
    }

    virtual auto processEvent(const sf::Event &event) -> void;

    virtual auto init() -> void = 0;
    virtual auto deinit() -> void = 0;
    virtual auto tick(float deltaTime) -> void = 0;
    virtual auto draw() -> void = 0;

protected:
    sf::RenderWindow m_window{};
    std::unique_ptr<Scene> m_scene{nullptr};

    std::uint32_t m_fps{0};
    sf::Time m_deltaTime{};

    float m_zoom{1.f};
private:
    sf::Font m_defaultFont{};
    sf::Text m_textFPS{};

    Settings m_settings;
};

} // namespace Engine

} // namespace usa
