/*
** EpiGimp Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include "Tools/Pencil.hpp"

void Pencil::toolGUI()
{
    ABrush::toolGUI();

    ImGui::Spacing();
    ImGui::ColorPicker4("Color", m_color);
}

sf::Color Pencil::getBrushColor()
{
    return sf::Color(static_cast<unsigned char>(m_color[0] * 255),
                     static_cast<unsigned char>(m_color[1] * 255),
                     static_cast<unsigned char>(m_color[2] * 255),
                     static_cast<unsigned char>(m_color[3] * 255));
}
