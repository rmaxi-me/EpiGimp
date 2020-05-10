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
    auto onTick(float deltaTime) -> void override;
    auto onDraw() const -> void override;

private:
    constexpr static auto MOVE_SPEED = 500.f;

    unsigned int m_width;
    unsigned int m_height;

    bool m_mouseGrabbed{false};
    sf::Vector2f m_grabPoint{};

    float m_deltaTime{};

    sf::Cursor m_cursor{};
    sf::RectangleShape m_canvas{};
    sf::Texture m_canvasTexture{};
    sf::Image m_canvasImage{};

    auto updateView(sf::Vector2f delta, float zoomDelta = 0.f) const -> void;
};
