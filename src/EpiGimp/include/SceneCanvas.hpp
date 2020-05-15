/*
** EpiGimp Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#pragma once

#include <SFML/Graphics.hpp>

#include <array>

#include "Engine/Scene.hpp"

#include "Tools/ATool.hpp"
#include "Layer.hpp"

class SceneCanvas final : public Engine::Scene {
public:
    SceneCanvas(unsigned int width, unsigned int height);
    explicit SceneCanvas(const std::vector<std::string_view> &files);

    auto onCreate(Engine::Application &app) -> bool override;
    auto onEvent(const sf::Event &event) -> void override;
    auto onTick(float deltaTime) -> void override;
    auto onDraw() -> void override;

    auto registerWindow(sf::RenderWindow &window) -> void override;

private:
    constexpr static auto MOVE_SPEED = 500.f;
    constexpr static auto TOOLS_COUNT = 3;

    std::vector<Layer> m_layers{};
    std::array<std::unique_ptr<ATool>, TOOLS_COUNT> m_tools;
    ATool *m_activeTool{nullptr};

    float m_deltaTime{};
    bool m_mouseGrabbed{false};
    sf::Vector2f m_grabPoint{};
    sf::Cursor m_cursor{};

    SceneCanvas();

    auto drawLayerWindow() -> void;
    auto drawToolbox() -> void;

    auto updateView(sf::Vector2f delta, float zoomDelta = 0.f) const -> void;
    auto swapLayers(decltype(m_layers)::reverse_iterator &current, int offset) -> void;

    [[nodiscard]] auto squash() const -> sf::Image;
    [[nodiscard]] auto getLargestImageSize() const -> sf::Vector2u;
};
