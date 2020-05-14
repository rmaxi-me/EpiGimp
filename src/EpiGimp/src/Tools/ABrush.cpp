/*
** EpiGimp Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include "Tools/ABrush.hpp"

std::uint32_t ABrush::m_brushSize{5};

void ABrush::onClickPressed(sf::Mouse::Button button, const sf::Vector2i &)
{
    if (button == sf::Mouse::Button::Left)
        m_mousePressed = true;
}

void ABrush::onClickReleased(sf::Mouse::Button button, const sf::Vector2i &)
{
    if (button == sf::Mouse::Button::Left)
        m_mousePressed = false;
}

void ABrush::onMouseMoved(const sf::Vector2i &)
{
    if (m_mousePressed) {}
}

void ABrush::toolGUI()
{
    static constexpr decltype(m_brushSize) MIN_SIZE = 1;
    static constexpr decltype(m_brushSize) MAX_SIZE = 500;

    ImGui::Text("Brush");
    ImGui::SliderScalar("Size", ImGuiDataType_U32, &m_brushSize, &MIN_SIZE, &MAX_SIZE);
    ImGui::Spacing();
    ImGui::Separator();
    ImGui::Spacing();

    ATool::toolGUI();
}
