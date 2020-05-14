/*
** EpiGimp Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#pragma once

#include "ATool.hpp"

class ABrush : public ATool {
private:
    bool m_mousePressed{false};

protected:
    static std::uint32_t m_brushSize;

public:
    ~ABrush() override = default;

    void onClickPressed(sf::Mouse::Button button, const sf::Vector2i &pos) override;
    void onClickReleased(sf::Mouse::Button button, const sf::Vector2i &pos) override;
    void onMouseMoved(const sf::Vector2i &pos) override;
    void toolGUI() override;

    virtual ImColor getBrushColor() = 0;

    inline const char *getName() override = 0;
    inline const char *getDescription() override = 0;
};
