#pragma once

#include <imgui.h>
#include <string_view>

#include <functional>

namespace usa {

namespace Engine {

class AWidget
{
protected:
    std::string_view m_name{};
    ImVec2 m_size{};
public:
    AWidget(const std::string &name, ImVec2 size = {}) : m_name(name), m_size(size) {}
    virtual ~AWidget() = default;

    auto setSize(const ImVec2 &size)        noexcept -> void { m_size = size; }
    auto setName(const std::string &name)   noexcept -> void { m_name = name; }

    auto getSize() -> const ImVec2 &        { return m_size; }
    auto getName() -> const std::string_view &   { return m_name; }

    virtual auto render() -> void = 0;
    virtual auto bindAction(std::function<void()>) -> void = 0;
};

}

}
