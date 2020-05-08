#include "Engine/UI/UiWindow.hpp"

namespace usa {

namespace Engine {

    auto UiWindow::render() -> void
    {
        if (ImGui::Begin(m_name.c_str(), &m_isOpen, m_window_flags))
        {
            for (auto &i : m_WindowList)
                i->render();
            for (auto &i : m_WidgetList)
                i->render();               
            ImGui::End();
        }
    }

    auto UiWindow::deleteWidget(const std::string &name) -> bool
    {
        for (auto i = m_WidgetList.begin(); i != m_WidgetList.end(); ++i)
        {
            if ((*i)->getName() == name) {
                m_WidgetList.erase(i);
                return true;
            }
        }
        return false;
    }

    auto UiWindow::getWidget(const std::string &name) -> std::optional<std::shared_ptr<AWidget>>
    {
        for (auto i = m_WidgetList.begin(); i != m_WidgetList.end(); ++i)
        {
            if ((*i)->getName() == name)
                return (*i);
        }
        return {};
    }

    auto UiWindow::deleteWindow(const std::string &name) -> bool
    {
        for (auto i = m_WindowList.begin(); i != m_WindowList.end(); ++i)
        {
            if ((*i)->getName() == name)
            {
                m_WindowList.erase(i);
                return true;
            }
        }
        return false;
    }

    auto UiWindow::getWindow(const std::string &name) -> std::optional<std::shared_ptr<UiWindow>>
    {
        for (auto i = m_WindowList.begin(); i != m_WindowList.end(); ++i)
        {
            if ((*i)->getName() == name)
                return (*i);
        }
        return {};
    }
}

}