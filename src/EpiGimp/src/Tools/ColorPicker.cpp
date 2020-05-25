/*
** EpiGimp Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include "Tools/ColorPicker.hpp"

void ColorPicker::onClickPressed(sf::Mouse::Button button, const sf::Vector2i &pos)
{
    if (button == sf::Mouse::Button::Left && m_activeLayer) {
        const auto coords = m_window->mapPixelToCoords(pos);

        if (m_activeLayer->sprite.getGlobalBounds().contains(coords)) {
            const auto relative = coords - m_activeLayer->sprite.getPosition();
            const auto color = m_activeLayer->image.getPixel(static_cast<unsigned int>(relative.x),
                                                             static_cast<unsigned int>(relative.y));

            m_color[0] = static_cast<float>(color.r) / 255.f;
            m_color[1] = static_cast<float>(color.g) / 255.f;
            m_color[2] = static_cast<float>(color.b) / 255.f;
            m_color[3] = static_cast<float>(color.a) / 255.f;
        }
    }
}

void ColorPicker::onClickReleased(sf::Mouse::Button, const sf::Vector2i &)
{
}

void ColorPicker::onMouseMoved(const sf::Vector2i &)
{
}

void ColorPicker::toolGUI()
{
    ATool::toolGUI();

    ImGui::ColorEdit4("Current Color", m_color);
}
