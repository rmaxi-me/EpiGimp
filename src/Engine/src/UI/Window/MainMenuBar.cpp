#include "Engine/UI/Window/MainMenuBar.hpp"
#include <iostream>

namespace Engine {
    
    auto MainMenuBar::render() -> void
    {
        if (ImGui::BeginMainMenuBar())
        {
            for (auto &i : m_WindowList)
                i->render();
            for (auto &i : m_WidgetList)
                i->render();
            ImGui::EndMainMenuBar();
        }
    }

} // namespace Engine
