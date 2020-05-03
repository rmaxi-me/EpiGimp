/*
** EpiGimp Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#pragma once

#include "Engine/Application.hpp"

class EpiGimpApp final : public Engine::Application {
public:
    EpiGimpApp(int ac, char **av);

    void init() override;
    void deinit() override;
    void tick(double deltaTime) override;
    void draw() override;
};
