/*
** EpiGimp Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

namespace usa {
namespace Engine {

    class Application;

    class Scene {
    public:
        Scene() = default;
        virtual ~Scene() = default;

        Scene(const Scene &) = default;
        Scene(Scene &&) = default;
        Scene &operator=(const Scene &) = default;
        Scene &operator=(Scene &&) = default;

        virtual auto registerWindow(sf::RenderWindow &window) -> void;

        virtual auto onCreate(Application &app) -> bool = 0;
        virtual auto onEvent(const sf::Event &event) -> void = 0;
        virtual auto onTick(float deltaTime) -> void = 0;
        virtual auto onDraw() const -> void = 0;
    protected:
        sf::RenderWindow *m_window{nullptr};
    };

} // namespace Engine
} // namespace usa
