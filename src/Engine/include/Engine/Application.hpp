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

        virtual auto init() -> void = 0;
        virtual auto deinit() -> void = 0;
        virtual auto tick(float deltaTime) -> void = 0;
        virtual auto draw() -> void = 0;

    protected:
        sf::RenderWindow m_window;
        std::unique_ptr<Scene> m_scene{nullptr};

        std::string_view m_binName;
        std::vector<std::string_view> m_arguments;

        std::uint32_t m_fps{0};
        sf::Time m_deltaTime{};

        float m_deltaTimeSeconds{0.f};
        float m_zoom{1.f};

        template<typename S, typename... Args>
        auto createScene(Args &&... args) -> bool
        {
            m_scene = std::make_unique<S>(std::forward<Args>(args)...);

            if (!m_scene->onCreate(*this)) {
                std::cerr << "Failed to create scene\n";
                m_scene.reset(nullptr);
                return false;
            }
            return true;
        }

        virtual auto reloadView() -> void final;
        virtual auto processEvent(const sf::Event &event) -> void;

    private:
        sf::Font m_defaultFont{};
        Settings m_settings;

        auto drawFps() const -> void;
    };

} // namespace Engine
} // namespace usa
