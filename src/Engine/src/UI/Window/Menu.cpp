#include "Engine/UI/Window/Menu.hpp"
#include <iostream>
namespace usa
{

    namespace Engine
    {

        auto Menu::render() -> void
        {
            if (ImGui::BeginMenu(m_name.c_str()))
            {
                for (auto &i : m_WindowList)
                    i->render();
                for (auto &i : m_WidgetList)
                    i->render();
                ImGui::EndMenu();
            }
        }

    } // namespace Engine

} // namespace usa
