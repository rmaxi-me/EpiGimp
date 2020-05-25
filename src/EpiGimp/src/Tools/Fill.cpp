/*
** EpiGimp Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include <iostream>
#include "Tools/Fill.hpp"

std::ostream &operator<<(std::ostream &os, const sf::Color &color)
{
    return os << "[" << static_cast<int>(color.r) << ", " << static_cast<int>(color.g) << ", "
              << static_cast<int>(color.b) << ", " << static_cast<int>(color.a) << "]";
}

void Fill::fill(const sf::Vector2u &pos, const sf::Color &toReplace, const sf::Vector2u &size, const std::size_t depth)
{
    if (depth > 25000 || pos.x >= size.x || pos.y >= size.y)
        return;

    const auto &thisColor = m_activeLayer->image.getPixel(pos.x, pos.y);

    if (colorSquaredDistance(toReplace, thisColor) <= static_cast<double>(DIST_MAX * m_tolerance)) {
        m_activeLayer->image.setPixel(pos.x, pos.y, m_sfColor);

        fill({pos.x - 1, pos.y}, toReplace, size, depth + 1);
        fill({pos.x + 1, pos.y}, toReplace, size, depth + 1);
        fill({pos.x, pos.y - 1}, toReplace, size, depth + 1);
        fill({pos.x, pos.y + 1}, toReplace, size, depth + 1);
    }
}

void Fill::paint(const sf::Vector2i &pos)
{
    const auto coords = m_window->mapPixelToCoords(pos);

    m_sfColor = sf::Color(static_cast<unsigned char>(m_color[0] * 255.f),
                          static_cast<unsigned char>(m_color[1] * 255.f),
                          static_cast<unsigned char>(m_color[2] * 255.f),
                          static_cast<unsigned char>(m_color[3] * 255.f));

    if (m_activeLayer->sprite.getGlobalBounds().contains(coords)) {
        const auto relative = coords - m_activeLayer->sprite.getPosition();
        const auto relativeU = sf::Vector2u{static_cast<unsigned int>(relative.x), static_cast<unsigned int>(relative.y)};
        const auto toReplace = m_activeLayer->image.getPixel(relativeU.x, relativeU.y);

        fill(relativeU, toReplace, m_activeLayer->image.getSize(), 0);
    }
}

void Fill::onClickPressed(sf::Mouse::Button button, const sf::Vector2i &pos)
{
    if (button == sf::Mouse::Button::Left && m_activeLayer) {
        paint(pos);
    }
}

void Fill::onClickReleased(sf::Mouse::Button, const sf::Vector2i &)
{
}

void Fill::onMouseMoved(const sf::Vector2i &)
{
}

void Fill::toolGUI()
{
    ATool::toolGUI();

    ImGui::Spacing();
    ImGui::ColorPicker4("Color", m_color);
    ImGui::Spacing();
    ImGui::SliderFloat("Tolerance", &m_tolerance, 0.f, 1.f);
}
