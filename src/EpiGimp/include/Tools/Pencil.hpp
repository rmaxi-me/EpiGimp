/*
** EpiGimp Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#pragma once

#include "ABrush.hpp"

class Pencil final : public ABrush {
public:
    ~Pencil() override = default;

    void toolGUI() override;
    sf::Color getBrushColor() override;

    inline const char *getName() override
    {
        return "Pencil";
    }

    inline const char *getDescription() override
    {
        return "Draw on the selected layer by holding left click.";
    }
};
