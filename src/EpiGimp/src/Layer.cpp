/*
** EpiGimp Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include "Layer.hpp"

Layer::Layer(unsigned int width, unsigned int height, sf::Color color)
{
    image.create(width, height, color);
    init();
}

Layer::Layer(const std::string_view &file)
{
    if (!image.loadFromFile(std::string(file)))
        throw std::runtime_error("Failed to load image");
    init();
}

auto Layer::init() -> void
{
    ratio = static_cast<float>(image.getSize().x) / static_cast<float>(image.getSize().y);
    texture.loadFromImage(image);

    sprite.setPosition(0.f, 0.f);
    sprite.setTexture(texture);
}

Layer::Layer(const sf::Image& newImage)
{
    image = newImage;
    init();
}
