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
            if (ImGui::MenuItem(m_name.data(), m_shortcut.data()))
            {
                if (f != nullptr)
                    f();
            }
        }
    } // namespace Engine

} // namespace usa