#include "Engine/UI/Widget/WMenuItem.hpp"

namespace usa
{

    namespace Engine
    {

        auto WMenuItem::bindAction(std::function<void()> func) -> void
        {
            f = func;
        }

        auto WMenuItem::render() -> void
        {
            if (ImGui::MenuItem(m_name.c_str(), m_shortcut.c_str()))
            {
                f();
            }
        }
    } // namespace Engine

} // namespace usa