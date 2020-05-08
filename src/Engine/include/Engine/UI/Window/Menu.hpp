#pragma once

#include "Engine/UI/UiWindow.hpp"

namespace usa
{

    namespace Engine
    {

        class Menu : public UiWindow
        {
        public:
            Menu(const std::string &name) : UiWindow(name) {}
            virtual ~Menu() = default;
            auto render() -> void override;
        };

    } // namespace Engine
} // namespace usa
