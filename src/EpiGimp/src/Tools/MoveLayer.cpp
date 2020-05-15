/*
** EpiGimp Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include "Tools/MoveLayer.hpp"

void MoveLayer::onClickPressed(sf::Mouse::Button button, const sf::Vector2i &pos)
{
    if (button == sf::Mouse::Left && m_window) {
        m_mouseGrabbed = true;
    }
}

void MoveLayer::onClickReleased(sf::Mouse::Button button, const sf::Vector2i &)
{
    if (button == sf::Mouse::Left) {
        m_mouseGrabbed = false;
    }
}

void MoveLayer::onMouseMoved(const sf::Vector2i &pos)
{
    if (m_mouseGrabbed && m_activeLayer) {
        sf::Vector2f middlePoint{m_window->mapPixelToCoords(pos)};
        middlePoint.x -= static_cast<float>(m_activeLayer->image.getSize().x) / 2.f;
        middlePoint.y -= static_cast<float>(m_activeLayer->image.getSize().y) / 2.f;

        m_activeLayer->sprite.setPosition(middlePoint);
    }
}

void MoveLayer::toolGUI()
{
    ATool::toolGUI();
}
