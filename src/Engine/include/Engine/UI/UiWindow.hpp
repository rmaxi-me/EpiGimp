#pragma once

#include <imgui.h>
#include <vector>
#include <memory>
#include <optional>
#include <string_view>

#include "AWidget.hpp"

namespace usa {

namespace Engine {

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
        UiWindow() = default;
        UiWindow(const std::string &name, ImGuiWindowFlags flags = 0) : m_window_flags(flags), m_name(name) {}
        virtual ~UiWindow() = default;

        auto open()     -> void { m_isOpen = true; }
        auto close()    -> void { m_isOpen = false; }
        virtual auto render()   -> void;
        
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

        auto addWindow(std::shared_ptr<UiWindow> wid) -> void { m_WindowList.emplace_back(wid); }
        auto deleteWindow(const std::string &name) -> bool;
        auto getWindow(const std::string &name) -> std::optional<std::shared_ptr<UiWindow>>;
    };
}

}
