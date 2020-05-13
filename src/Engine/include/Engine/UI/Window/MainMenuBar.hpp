#pragma once

#include "Engine/UI/UiWindow.hpp"

namespace Engine {

/**
 * @class MainMenuBar
 *
 * @brief Main menu bar window class, create a main menu bar window on top of the screen
 */
class MainMenuBar : public UiWindow {
public:
    /**
     * @brief Construct a new Main Menu Bar object
     *
     */
    MainMenuBar() { }
    /**
     * @brief Destroy the Main Menu Bar object
     *
     */
    virtual ~MainMenuBar() = default;
    /**
     * @brief Render the window and everything it contains
     *
     */
    auto render() -> void override;
};

} // namespace Engine
