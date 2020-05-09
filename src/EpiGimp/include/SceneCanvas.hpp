/*
** EpiGimp Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#pragma once

#include <SFML/Graphics.hpp>

#include "Engine/Scene.hpp"

class SceneCanvas final : public usa::Engine::Scene {
public:
    SceneCanvas(unsigned int width, unsigned int height);
    explicit SceneCanvas(const std::string_view &file);

    auto onCreate(usa::Engine::Application &app) -> bool override;
    auto onEvent(const sf::Event &event) -> void override;
    auto onTick(const sf::RenderWindow &window, float) -> void override;
    auto onDraw(sf::RenderWindow &window) const -> void override;

private:
    unsigned int m_width;
    unsigned int m_height;

    sf::RectangleShape m_rect{};
    sf::Texture m_canvasTexture{};
    sf::Image m_canvasImage{};
};
