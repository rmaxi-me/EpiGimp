/*
** EpiGimp Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

namespace Engine {

class Application;

/**
 * @brief The Scene abstract class represent a scene in your application.
 */
class Scene {
public:
    Scene() = default;
    virtual ~Scene() = default;

    Scene(const Scene &) = default;
    Scene(Scene &&) = default;
    Scene &operator=(const Scene &) = default;
    Scene &operator=(Scene &&) = default;

    /**
     * @brief Registers the window
     * @param window Application window.
     */
    virtual auto registerWindow(sf::RenderWindow &window) -> void;

    /**
     * @brief On scene creation. Called once the scene is ready to be used.
     * @param app
     * @return
     */
    virtual auto onCreate(Application &app) -> bool = 0;

    /**
     * @brief Handle scene events. Called after Application events.
     * @param event Event to be processed.
     */
    virtual auto onEvent(const sf::Event &event) -> void = 0;

    /**
     * @brief Scene logic.
     * @param deltaTime Frame time.
     */
    virtual auto onTick(float deltaTime) -> void = 0;

    /**
     * @brief Draws the scene.
     */
    virtual auto onDraw() -> void = 0;

protected:
    sf::RenderWindow *m_window{nullptr};
};

} // namespace Engine
