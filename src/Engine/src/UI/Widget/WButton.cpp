#include "Engine/UI/Widget/WButton.hpp"

namespace usa {

namespace Engine {

    auto WButton::bindAction(std::function<void()> func) -> void
    {
        f = func;
    }

    auto WButton::render() -> void
    {
        if (ImGui::Button(m_name.data(), m_size))
        {
            f();
        }
    }
}

}