/*
** EpiGimp Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include "Engine/Scene.hpp"

auto usa::Engine::Scene::registerWindow(sf::RenderWindow &window) -> void { m_window = &window; }
