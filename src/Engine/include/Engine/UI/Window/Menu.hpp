#pragma once

#include <string_view>
#include "Engine/UI/UiWindow.hpp"

namespace usa
{

    namespace Engine
    {

        /**
         * @class Menu 
         * 
         * @brief Menu window class, create a menu window which is to be filled by MenuItem
         */
        class Menu : public UiWindow
        {
        public:
            /**
             * @brief Construct a new Menu object
             * 
             * @param name The name of the Menu
             */
            Menu(const std::string_view &name) : UiWindow(name) {}
            /**
             * @brief Destroy the Menu object
             * 
             */
            virtual ~Menu() = default;
            /**
             * @brief Render the window and everything it contains 
             * 
             */
            auto render() -> void override;
        };

    } // namespace Engine
} // namespace usa
