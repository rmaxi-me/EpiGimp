/*
** EpiGimp Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#pragma once

#include <cmath>

#include "ATool.hpp"

class Fill final : public ATool {
private:
    float m_color[4] = {0, 0, 0, 1};
    float m_tolerance = 0.f;

    sf::Color m_sfColor{};

    static constexpr float DIST_MAX = (255.0 * 255.0);

    static inline double colorSquaredDistance(const sf::Color &color1, const sf::Color &color2)
    {
        return std::pow(color2.r - color1.r, 2) + std::pow(color2.g - color1.g, 2) + std::pow(color2.b - color1.b, 2);
    }

    void fill(const sf::Vector2u &pos, const sf::Color &toReplace, const sf::Vector2u &size, const std::size_t depth);
    void paint(const sf::Vector2i &pos);

public:
    void onClickPressed(sf::Mouse::Button button, const sf::Vector2i &pos) override;
    void onClickReleased(sf::Mouse::Button button, const sf::Vector2i &pos) override;
    void onMouseMoved(const sf::Vector2i &pos) override;
    void toolGUI() override;

    inline const char *getName() override
    {
        return "Fill";
    }

    inline const char *getDescription() override
    {
        return "Replace a color by another on the canvas.";
    }
};
