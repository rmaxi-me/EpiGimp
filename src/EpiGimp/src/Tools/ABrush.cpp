/*
** EpiGimp Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include <cmath>

#include "Tools/ABrush.hpp"

std::uint32_t ABrush::m_brushSize{10};

void ABrush::paint(const sf::Vector2i &pos)
{
    const auto coords = m_window->mapPixelToCoords(pos);
    if (m_activeLayer->sprite.getGlobalBounds().contains(coords)) {
        const auto relative = coords - m_activeLayer->sprite.getPosition();
        drawCircle(m_activeLayer->image, relative);
    }
}

void ABrush::onClickPressed(sf::Mouse::Button button, const sf::Vector2i &pos)
{
    if (button == sf::Mouse::Button::Left) {
        m_mousePressed = true;
        if (m_activeLayer)
            paint(pos);
    }
}

void ABrush::onClickReleased(sf::Mouse::Button button, const sf::Vector2i &)
{
    if (button == sf::Mouse::Button::Left)
        m_mousePressed = false;
}

void ABrush::onMouseMoved(const sf::Vector2i &pos)
{
    if (m_mousePressed && m_activeLayer) {
        paint(pos);
    }
}

void ABrush::drawCircle(sf::Image &image, const sf::Vector2f &pos)
{
    const auto color = getBrushColor();
    const auto radius = static_cast<float>(m_brushSize) / 2.f;
    const auto size = image.getSize();
    const sf::Vector2i start{static_cast<int>(pos.x - radius), static_cast<int>(pos.y - radius)};
    const sf::Vector2i end{static_cast<int>(pos.x + radius), static_cast<int>(pos.y + radius)};

    for (auto x = start.x; x <= end.x; ++x) {
        for (auto y = start.y; y <= end.y; ++y) {
            if (x < 0 || y < 0 || x >= static_cast<int>(size.x) || y >= static_cast<int>(size.y))
                continue;

            if (std::pow(static_cast<float>(x) - pos.x, 2) + std::pow(static_cast<float>(y) - pos.y, 2)
                <= std::pow(radius, 2)) {
                image.setPixel(static_cast<unsigned int>(x), static_cast<unsigned int>(y), color);
            }
        }
    }
}

void ABrush::toolGUI()
{
    static constexpr decltype(m_brushSize) MIN_SIZE = 1;
    static constexpr decltype(m_brushSize) MAX_SIZE = 250;

    ImGui::Text("Brush");
    ImGui::SliderScalar("Size", ImGuiDataType_U32, &m_brushSize, &MIN_SIZE, &MAX_SIZE);
    ImGui::Spacing();
    ImGui::Separator();
    ImGui::Spacing();

    ATool::toolGUI();
}
