/*
** EpiGimp Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <imgui.h>

#include "Layer.hpp"

class ATool {
protected:
    sf::RenderWindow *m_window{nullptr};
    Layer *m_activeLayer{nullptr};
public:
    ATool();
    virtual ~ATool();

    void handleEvent(const sf::Event &event);
    void registerWindow(sf::RenderWindow &window);
    void setActiveLayer(Layer &layer);

    virtual void onClickPressed(sf::Mouse::Button button, const sf::Vector2i &pos) = 0;
    virtual void onClickReleased(sf::Mouse::Button button, const sf::Vector2i &pos) = 0;
    virtual void onMouseMoved(const sf::Vector2i &pos) = 0;
    virtual void toolGUI();

    inline virtual const char *getName() = 0;
    inline virtual const char *getDescription() = 0;
};
