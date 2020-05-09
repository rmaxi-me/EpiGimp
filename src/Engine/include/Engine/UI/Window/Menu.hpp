#pragma once

#include <string_view>
#include "Engine/UI/UiWindow.hpp"

namespace usa
{

    namespace Engine
    {

        class Menu : public UiWindow
        {
        public:
            Menu(const std::string_view &name) : UiWindow(name) {}
            virtual ~Menu() = default;
            auto render() -> void override;
        };

    } // namespace Engine
} // namespace usa
