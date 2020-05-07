/*
** EpiGimp Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include "SceneCanvas.hpp"

SceneCanvas::SceneCanvas(unsigned int width, unsigned int height)
        : m_width{width}, m_height{height}
{
}

bool SceneCanvas::onCreate()
{
    m_canvasImage.create(m_width, m_height, sf::Color::White);
    m_canvasTexture.create(m_width, m_height);
    m_canvasTexture.setSmooth(false);

    m_rect.setPosition(0, 0);
    m_rect.setSize({static_cast<float>(m_width), static_cast<float>(m_height)});
    m_rect.setTexture(&m_canvasTexture);
    return true;
}

void SceneCanvas::onEvent(const sf::Event &)
{
}

void SceneCanvas::onTick(const sf::RenderWindow &, float)
{
    // Temporary
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        auto pos = sf::Mouse::getPosition();
        if (m_rect.getGlobalBounds().contains(static_cast<float>(pos.x), static_cast<float>(pos.y))) {
            m_canvasImage.setPixel(static_cast<unsigned int>(pos.x), static_cast<unsigned int>(pos.y), sf::Color::Black);
        }
    }

    m_canvasTexture.update(m_canvasImage);
}

void SceneCanvas::onDraw(sf::RenderWindow &window) const
{
    window.draw(m_rect);
}
