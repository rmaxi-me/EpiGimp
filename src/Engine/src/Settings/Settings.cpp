/*
** EpiGimp Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include <fstream>
#include <iomanip>

#include "Engine/Settings/Settings.hpp"

void usa::Engine::to_json(Json &json, const usa::Engine::Settings &settings)
{
    json = Json{
            {"width", settings.width},
            {"height", settings.height},
            {"fps_limit", settings.fps_limit},
            {"fullscreen", settings.fullscreen},
    };
}

void usa::Engine::from_json(const Json &json, usa::Engine::Settings &settings)
{
    json.at("width").get_to(settings.width);
    json.at("height").get_to(settings.height);
    json.at("fps_limit").get_to(settings.fps_limit);
    json.at("fullscreen").get_to(settings.fullscreen);
}

auto usa::Engine::Settings::fromFile(const std::string_view &path) -> Settings
{
    Settings s;
    std::ifstream file{path.data()};

    if (file) {
        Json json;
        file >> json;
        s = json;
    }
    return s;
}

auto usa::Engine::Settings::save(const std::string_view &path) const -> void
{
    std::ofstream file{path.data()};

    if (file) {
        Json json = *this;
        file << std::setw(4) << json;
    }
}
