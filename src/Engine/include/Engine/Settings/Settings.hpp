/*
** EpiGimp Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#pragma once

#include <cstdint>

#include "Engine/Json.hpp"

namespace Engine {

struct Settings {
    static constexpr auto CONFIG_PATH = "Resources/config.json";

    // Default values that can be overwritten in the config file
    std::uint32_t width{1200};
    std::uint32_t height{675};
    std::uint32_t fps_limit{0};
    bool fullscreen{false};

    static auto fromFile(const std::string_view &path = CONFIG_PATH) -> Settings;
    auto save(const std::string_view &path = CONFIG_PATH) const -> void;
};

void to_json(Json &json, const Settings &settings);
void from_json(const Json &json, Settings &settings);
} // namespace Engine
