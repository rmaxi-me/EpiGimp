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

/**
 * @brief The Settings class represents the application's settings. It is serializable/deserializable in JSON format.
 */
struct Settings {
    /**
     * @brief Where the config file is located.
     */
    static constexpr auto CONFIG_PATH = "Resources/config.json";

    // Default values that can be overwritten in the config file
    std::uint32_t width{1600};
    std::uint32_t height{900};
    std::uint32_t fps_limit{0};
    bool fullscreen{false};

    /**
     * @brief Loads settings from a JSON file.
     * @param path Where to load the config from. Defaults to CONFIG_PATH.
     * @return Settings class.
     */
    static auto fromFile(const std::string_view &path = CONFIG_PATH) -> Settings;

    /**
     * @brief Saves current application settings.
     * @param path Where to save the config to. Defaults to CONFIG_PATH.
     */
    auto save(const std::string_view &path = CONFIG_PATH) const -> void;
};

/**
 * @brief Used by nlohmann::json serialization.
 * @param json JSON object.
 * @param settings Settings object.
 */
void to_json(Json &json, const Settings &settings);

/**
 * @brief Used by nlohmann::json deserialization.
 * @param json JSON object.
 * @param settings Settings object.
 */
void from_json(const Json &json, Settings &settings);
} // namespace Engine
