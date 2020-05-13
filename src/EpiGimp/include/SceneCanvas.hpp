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
    explicit SceneCanvas(const std::vector<std::string_view> &files);

    auto onCreate(usa::Engine::Application &app) -> bool override;
    auto onEvent(const sf::Event &event) -> void override;
    auto onTick(float deltaTime) -> void override;
    auto onDraw() -> void override;

private:
    constexpr static auto MOVE_SPEED = 500.f;

    struct Layer {
        sf::Texture texture;
        sf::Image image;
        sf::Sprite sprite;

        float ratio{};
        bool hidden{false};

        Layer(unsigned int width, unsigned int height, sf::Color color = sf::Color::White);
        explicit Layer(const std::string_view &file);

        auto init() -> void;
    };

    std::vector<Layer> m_layers{};

    float m_deltaTime{};
    bool m_mouseGrabbed{false};
    sf::Vector2f m_grabPoint{};
    sf::Cursor m_cursor{};

    auto drawLayerWindow() -> void;

    auto updateView(sf::Vector2f delta, float zoomDelta = 0.f) const -> void;
    auto swapLayers(decltype(m_layers)::reverse_iterator &current, int offset) -> void;

    [[nodiscard]] auto squash() const -> sf::Image;
    [[nodiscard]] auto getLargestImageSize() const -> sf::Vector2u;
};
