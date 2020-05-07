#pragma once

#include <imgui.h>
#include <vector>
#include <memory>

#include <optional>
#include "AWidget.hpp"

namespace usa {

namespace Engine {

    class UiWindow
    {
    private:
        std::string m_name{};
        ImGuiWindowFlags m_window_flags{0};
        bool m_isOpen = true;

        ImVec2 m_size{};
        ImVec2 m_position{};
        std::vector<std::shared_ptr<AWidget>> m_WidgetList;

    public:
        UiWindow(const std::string &name,ImGuiWindowFlags flags = 0) : m_name(name), m_window_flags(flags) {}
        ~UiWindow() = default;

        auto open()     -> void { m_isOpen = true; }
        auto close()    -> void { m_isOpen = false; }
        auto render()   -> void;
        
        auto setWindowFlags(ImGuiWindowFlags flags) noexcept -> void { m_window_flags = flags; }
        auto setPosition(const ImVec2 &pos) noexcept    -> void { m_position = pos; }
        auto setSize(const ImVec2 &size)    noexcept    -> void { m_size = size; }
        auto setName(const std::string &name) noexcept  -> void { m_name = name; }

        auto getFlags()     -> ImGuiWindowFlags &{ return m_window_flags; }
        auto getPosition()  -> const ImVec2 & { return m_position; }
        auto getSize()      -> const ImVec2 & { return m_size; }
        auto getName()      -> const std::string & { return m_name; }

        auto addWidget(std::shared_ptr<AWidget> wid) -> void { m_WidgetList.emplace_back(wid); }
        auto deleteWidget(const std::string &name)  -> bool;
        auto getWidget(const std::string &name)     -> std::optional<std::shared_ptr<AWidget>>; 
    };
}

}
