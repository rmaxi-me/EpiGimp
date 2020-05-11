#pragma once

#include <imgui.h>
#include <vector>
#include <memory>
#include <optional>
#include <string_view>

#include "AWidget.hpp"

namespace usa {

namespace Engine {

    /**
     * @class UiWindow
     * 
     * @brief Window base class
     * 
     */
    class UiWindow
    {
    private:
        ImGuiWindowFlags m_window_flags{0};
        bool m_isOpen = true;

        ImVec2 m_size{};
        ImVec2 m_position{};
    protected:
        std::string_view m_name{};
        std::vector<std::shared_ptr<AWidget>> m_WidgetList{};
        std::vector<std::shared_ptr<UiWindow>> m_WindowList{};
    public:
        /**
         * @brief Construct a new Ui Window object
         * 
         */
        UiWindow() = default;

        /**
         * @brief Construct a new Ui Window object
         * 
         * @param name The name of the window, the name may be render
         * @param flags The flags parameters of the window
         */
        UiWindow(const std::string_view &name, ImGuiWindowFlags flags = 0) : m_window_flags(flags), m_name(name) {}

        /**
         * @brief Destroy the Ui Window object
         * 
         */
        virtual ~UiWindow() = default;

        /**
         * @brief Open the window
         * 
         */
        auto open()     -> void { m_isOpen = true; }

        /**
         * @brief Close the window
         * 
         */
        auto close()    -> void { m_isOpen = false; }

        /**
         * @brief Render the window and everything it contains
         * 
         */
        virtual auto render()   -> void;

        /**
         * @brief Set the Window Flags object
         * 
         * @param flags The value of the flags, different value will trigger different options
         */
        auto setWindowFlags(ImGuiWindowFlags flags) noexcept -> void { m_window_flags = flags; }

        /**
         * @brief Set the Position object
         * 
         * @param pos The new postion of the object
         */
        auto setPosition(const ImVec2 &pos) noexcept    -> void { m_position = pos; }

        /**
         * @brief Set the Size object
         * 
         * @param size The new size of the object
         */
        auto setSize(const ImVec2 &size)    noexcept    -> void { m_size = size; }

        /**
         * @brief Set the Name object
         * 
         * @param name The new name of the object
         */
        auto setName(const std::string_view &name) noexcept  -> void { m_name = name; }

        /**
         * @brief Get the Flags object
         * 
         * @return ImGuiWindowFlags& 
         */
        auto getFlags()     -> ImGuiWindowFlags &{ return m_window_flags; }

        /**
         * @brief Get the Position object
         * 
         * @return const ImVec2& 
         */
        auto getPosition()  -> const ImVec2 & { return m_position; }
        /**
         * @brief Get the Size object
         * 
         * @return const ImVec2& 
         */
        auto getSize()      -> const ImVec2 & { return m_size; }
        /**
         * @brief Get the Name object
         * 
         * @return const std::string_view& 
         */
        auto getName()      -> const std::string_view & { return m_name; }

        /**
         * @brief Add a new widget to the window
         * 
         * @param widget The new widget to add 
         */
        auto addWidget(std::shared_ptr<AWidget> widget) -> void { m_WidgetList.emplace_back(widget); }
        
        /**
         * @brief Delete a widget store in the window
         * 
         * @param name The name of the widget to delete
         * @return true Return true if a widget was delete
         * @return false Return false if no widget was found
         */
        auto deleteWidget(const std::string_view &name)  -> bool;
        
        /**
         * @brief Get the Widget object
         * 
         * @param name The name of the widget to get
         * @return std::optional<std::shared_ptr<AWidget>> Return a widget smart pointer if found
         * @return nullopt Return nullopt if the widget was not found
         */
        auto getWidget(const std::string_view &name)     -> std::optional<std::shared_ptr<AWidget>>;

        /**
         * @brief Add a new sub Window in the current window
         * 
         * @param win The new window to add 
         */
        auto addWindow(std::shared_ptr<UiWindow> win) -> void { m_WindowList.emplace_back(win); }
        
        /**
         * @brief Delete a sub-window store in the window
         * 
         * @param name the name of the sub-window to delete
         * @return true return true if a window was deleted
         * @return false return false otherwise
         */
        auto deleteWindow(const std::string_view &name) -> bool;
        
        /**
         * @brief Get the Window object
         * 
         * @param name The name of the window object to get
         * @return std::optional<std::shared_ptr<UiWindow>> return a UiWindow smart pointer
         * @return nullopt return nullopt otherwise
         */
        auto getWindow(const std::string_view &name) -> std::optional<std::shared_ptr<UiWindow>>;
    };
}

}
