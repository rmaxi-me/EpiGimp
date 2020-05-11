/**
 * @file AWidget.hpp
 * @author Pierre Langlois (pierre.langlois@epitech.eu)
 * @brief 
 * @version 0.1
 * @date 2020-05-11
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#pragma once

#include <imgui.h>
#include <string_view>

#include <functional>

namespace usa {

namespace Engine {

/**
 * @class AWidget
 * 
 * @brief abstract widget base class
 * 
 */
class AWidget
{
protected:
    std::string_view m_name{};
    ImVec2 m_size{};
public:
    /**
     * @brief Construct a new AWidget object
     * 
     * @param name The name of the widget, the name will be rendered
     * @param size The size of the widget
     */
    AWidget(const std::string_view &name, ImVec2 size = {}) : m_name(name), m_size(size) {}
    
    /**
     * @brief Destroy the AWidget object
     * 
     */
    virtual ~AWidget() = default;

    /**
     * @brief Set the size of the object
     * 
     * @param size set the size of the widget
     */
    auto setSize(const ImVec2 &size)        noexcept -> void { m_size = size; }
    /**
     * @brief Set the name of the object
     * 
     * @param name 
     */
    auto setName(const std::string_view &name)   noexcept -> void { m_name = name; }

    /**
     * @brief Get the size of the object
     * 
     * @return const ImVec2& 
     */
    auto getSize() -> const ImVec2 &        { return m_size; }

    /**
     * @brief Get the name of the object
     * 
     * @return const std::string_view& 
     */
    auto getName() -> const std::string_view &   { return m_name; }

    /**
     * @brief render the widget
     * 
     */
    virtual auto render() -> void = 0;
 
    /**
     * @brief bind an action to the widget
     * 
     * @param std::function<void()> take an std::function to bind 
     */
    virtual auto bindAction(std::function<void()>) -> void = 0;
};

}

}
