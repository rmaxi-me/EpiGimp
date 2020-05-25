#pragma once

#include "Engine/UI/AWidget.hpp"
#include <functional>
#include <string_view>

namespace Engine {

/**
 * @class WSeparator
 *
 * @brief Widget drawing a separator line in a menu
 */
class WSeparator : public AWidget {
private:
    std::function<void()> f;

public:
    /**
     * @brief Construct a new WSeparator object
     *
     */
    WSeparator(const std::string_view &name = "", ImVec2 size = {}) : AWidget(name, size)
    {
    }
    /**
     * @brief Destroy the WSeparator object
     *
     */
    virtual ~WSeparator() = default;

    auto bindAction(std::function<void()> func) -> void override;
    /**
     * @brief Render the separator
     *
     */
    auto render() -> void override
    {
        ImGui::Separator();
    };
};

} // namespace Engine
