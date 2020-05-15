/*
** EpiGimp Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#pragma once

#include "ATool.hpp"

class MoveLayer final : public ATool {
private:
    bool m_mouseGrabbed{false};
public:
    ~MoveLayer() override = default;

    void onClickPressed(sf::Mouse::Button button, const sf::Vector2i &pos) override;
    void onClickReleased(sf::Mouse::Button button, const sf::Vector2i &pos) override;
    void onMouseMoved(const sf::Vector2i &pos) override;
    void toolGUI() override;

    inline const char *getName() override
    {
        return "Move Layer";
    }

    inline const char *getDescription() override
    {
        return "Left click and drag to move a layer on the canvas.";
    }
};
