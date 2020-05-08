#include "Engine/UI/Window/Menu.hpp"

namespace usa
{

    namespace Engine
    {

        auto Menu::render() -> void
        {
            if (ImGui::BeginMenu())
            {
                for (auto &i : m_WidgetList)
                    i->render();
            }
            ImGui::EndMenu();
        }

    } // namespace Engine

} // namespace usa
