/*
** EpiGimp Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#pragma once

#include <SFML/Graphics.hpp>

struct Layer {
    sf::Texture texture;
    sf::Image image;
    sf::Sprite sprite;

    float ratio{};
    bool hidden{false};

    Layer(unsigned int width, unsigned int height, sf::Color color = sf::Color::White);
    explicit Layer(const std::string_view &file);
    explicit Layer(const sf::Image&);
    auto init() -> void;
};
