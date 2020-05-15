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
        m_grabPoint = m_window->mapPixelToCoords(pos);
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
        const auto delta = m_window->mapPixelToCoords(pos) - m_grabPoint;
        m_activeLayer->sprite.move(delta);
    }
}

void MoveLayer::toolGUI()
{
    ATool::toolGUI();
}
