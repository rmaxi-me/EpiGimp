#pragma once

#include "Engine/UI/AWidget.hpp"
#include <functional>

namespace usa
{

    namespace Engine
    {

        class WMenuItem : public AWidget
        {
        private:
            std::string m_shortcut{};
            std::function<void()> f;
        public:
            WMenuItem(const std::string &name, const std::string &shortcut = "") : AWidget(name, ImVec2()), m_shortcut(shortcut) {}
            virtual ~WMenuItem() = default;

            auto bindAction(std::function<void()> func) -> void override;
            auto render() -> void override;
        };

    } // namespace Engine

} // namespace usa