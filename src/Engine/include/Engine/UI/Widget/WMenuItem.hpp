#pragma once

#include "Engine/UI/AWidget.hpp"
#include <functional>
#include <string_view>

namespace usa
{

    namespace Engine
    {

        /**
         * @class WMenuItem
         * 
         * @brief Widget class representing a Menu Item
         * 
         */
        class WMenuItem : public AWidget
        {
        private:
            std::string_view m_shortcut{};
            std::function<void()> f;
        public:
            /**
             * @brief Construct a new WMenuItem object
             * 
             * @param name The name of the menu item
             * @param shortcut The sub name of the menu item
             */
            WMenuItem(const std::string_view &name, const std::string_view &shortcut = "") : AWidget(name, ImVec2()), m_shortcut(shortcut) {}

            /**
             * @brief Destroy the WMenuItem object
             * 
             */
            virtual ~WMenuItem() = default;

            /**
             * @brief Bind an action to the menu item
             * 
             * @param func The function action to bind
             */
            auto bindAction(std::function<void()> func) -> void override;
            
            /**
             * @brief Render the menu item and check if it's triggered. If it is, call the bound function
             * 
             */
            auto render() -> void override;
        };

    } // namespace Engine

} // namespace usa
