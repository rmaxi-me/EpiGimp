#pragma once

#include "Engine/UI/AWidget.hpp"
#include <functional>
#include <string_view>

namespace usa
{

    namespace Engine
    {

        class WSeparator : public AWidget
        {
        private:
            std::function<void()> f;

        public:
            WSeparator(const std::string_view &name, ImVec2 size = {}) : AWidget(name, size) {}
            virtual ~WSeparator() = default;

            auto bindAction(std::function<void()> func) -> void override;
            auto render() -> void override
            {
                ImGui::Separator();
            };
        };

    } // namespace Engine

} // namespace usa
