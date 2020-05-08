#include "Engine/UI/Window/MainMenuBar.hpp"

namespace usa {
    
namespace Engine {
    
    auto MainMenuBar::render() -> void
    {
        if (ImGui::BeginMainMenuBar())
        {
            for (auto &i : m_WidgetList)
                i->render();
        }
        ImGui::EndMainMenuBar();
    }

} // namespace Engine

} // namespace usa
