/*
** EpiGimp Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/
#include <SFML/Graphics.hpp>
#include <imgui.h>
#include "imgui-SFML.h"
#include "EpiGimpApp.hpp"

#include "Engine/UI/UiWindow.hpp"
#include "Engine/UI/Window/Menu.hpp"
#include "Engine/UI/AWidget.hpp"
#include "Engine/UI/Widget/WButton.hpp"
#include "Engine/UI/Widget/WMenuItem.hpp"
#include "Engine/UI/Window/MainMenuBar.hpp"
#include "Engine/UI/Window/Menu.hpp"
#include <iostream>
#include <functional>
#include "SceneCanvas.hpp"

EpiGimpApp::EpiGimpApp(int ac, char **av) : Application{ac, av} { }

auto EpiGimpApp::processEvent(const sf::Event &event) -> void { Application::processEvent(event); }

auto EpiGimpApp::init() -> void
{
    if (m_arguments.empty()) {
        createScene<SceneCanvas>(800, 800);
    } else {
        createScene<SceneCanvas>(m_arguments);
    }
}

auto EpiGimpApp::deinit() -> void { }

auto EpiGimpApp::tick(float) -> void { }

auto EpiGimpApp::draw() -> void { }
