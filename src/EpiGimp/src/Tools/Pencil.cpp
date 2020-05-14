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

ImColor Pencil::getBrushColor()
{
    return ImColor(m_color[0], m_color[1], m_color[2], m_color[3]);
}
