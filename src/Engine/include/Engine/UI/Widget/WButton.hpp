#pragma once

#include "Engine/UI/AWidget.hpp"
#include <functional>
#include <string_view>

namespace usa {

namespace Engine {

    /**
     * @class WButton
     * 
     * @brief Widget class representing a button
     */
    class WButton : public AWidget
    {
    private:
        std::function<void()> f;
 
    public :
        /**
         * @brief Construct a new WButton object
         * 
         * @param name The name of the button
         * @param size The size of the button
         */
        WButton(std::string_view name, ImVec2 size = {}) : AWidget(name, size) {}

        /**
         * @brief Destroy the WButton object
         * 
         */
        virtual ~WButton() = default;

        /**
         * @brief Bind an action to the button
         * 
         * @param func The function action to bind
         */
        auto bindAction(std::function<void()> func) -> void override;
        
        /**
         * @brief Render the button and check if it's triggered. If it is, call the bound function
         * 
         */
        auto render() -> void override;
    };

}

}
