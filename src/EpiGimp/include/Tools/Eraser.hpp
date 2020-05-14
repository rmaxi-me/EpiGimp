/*
** EpiGimp Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#pragma once

#include "ABrush.hpp"

class Eraser final : public ABrush {
public:
    ~Eraser() override = default;

    sf::Color getBrushColor() override;

    inline const char *getName() override
    {
        return "Eraser";
    }

    inline const char *getDescription() override
    {
        return "Erase pixels on the selected layer.";
    }
};
