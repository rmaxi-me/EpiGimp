#pragma once

#include "Engine/UI/UiWindow.hpp"


namespace usa {

namespace Engine {

    class MainMenuBar : public UiWindow
    {
    private:
    public:
        MainMenuBar() {}
        virtual ~MainMenuBar() = default;
        auto render() -> void override;
    };

} // namespace Engine
} // namespace usa
