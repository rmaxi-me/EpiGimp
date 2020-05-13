/*
** EpiGimp Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#pragma once

#include <memory>

#include <Engine/UI/UiWindow.hpp>
#include <Engine/Application.hpp>

class EpiGimpApp final : public Engine::Application {
private:
    auto drawMainMenuBar() -> void;
    auto drawFileMenu() -> void;
    auto drawEditMenu() -> void;
    auto drawSelectMenu() -> void;
    auto drawViewMenu() -> void;
    auto drawImageMenu() -> void;
    auto drawLayerMenu() -> void;
    auto drawColorMenu() -> void;
    auto drawFiltersMenu() -> void;
    auto drawWindowsMenu() -> void;
public:
    EpiGimpApp(int ac, char **av);
    ~EpiGimpApp() override = default;

    auto processEvent(const sf::Event &event) -> void override;
    auto init() -> void override;
    auto deinit() -> void override;
    auto tick(float deltaTime) -> void override;
    auto draw() -> void override;
};
