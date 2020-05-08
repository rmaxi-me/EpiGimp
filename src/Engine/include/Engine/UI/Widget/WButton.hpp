#pragma once

#include "Engine/UI/AWidget.hpp"
#include <functional>

namespace usa {

namespace Engine {

    class WButton : public AWidget
    {
    private:
        std::function<void()> f;
 
    public :
        WButton(std::string name, ImVec2 size = {}) : AWidget(name, size) {}
        virtual ~WButton() = default;

        auto bindAction(std::function<void()> func) -> void override;
        auto render() -> void override;
    };

}

}