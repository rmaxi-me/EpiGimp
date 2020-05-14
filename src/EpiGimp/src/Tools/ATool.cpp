/*
** EpiGimp Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include "Tools/ATool.hpp"

ATool::ATool() = default;

ATool::~ATool() = default;

void ATool::registerWindow(sf::RenderWindow &window)
{
    m_window = &window;
}

void ATool::setActiveLayer(Layer &layer)
{
    m_activeLayer = &layer;
}

void ATool::handleEvent(const sf::Event &event)
{
    switch (event.type) {
    case sf::Event::EventType::MouseButtonPressed:
        onClickPressed(event.mouseButton.button, {event.mouseButton.x, event.mouseButton.y});
        break;
    case sf::Event::EventType::MouseButtonReleased:
        onClickReleased(event.mouseButton.button, {event.mouseButton.x, event.mouseButton.y});
        break;
    case sf::Event::EventType::MouseMoved:
        onMouseMoved({event.mouseMove.x, event.mouseMove.y});
        break;
    default:
        break;
    }
}

void ATool::toolGUI()
{
    ImGui::TextColored(ImColor{255, 233, 0, 255}, "%s", getName());
    ImGui::TextColored(ImColor{107, 185, 232, 255}, "%s", getDescription());
}
