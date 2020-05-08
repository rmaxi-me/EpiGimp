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

usa::EpiGimpApp::EpiGimpApp(int ac, char **av) : Application{ac, av} { }

auto usa::EpiGimpApp::processEvent(const sf::Event &event) -> void
{
    Application::processEvent(event);

    if (event.type == sf::Event::MouseWheelScrolled) {
        m_zoom += 0.1f * event.mouseWheelScroll.delta;
        reloadView();
    }
}

auto usa::EpiGimpApp::init() -> void { createScene<SceneCanvas>(800, 800); }

auto usa::EpiGimpApp::deinit() -> void { }

auto usa::EpiGimpApp::tick(float) -> void { }
auto usa::EpiGimpApp::draw() -> void
{
    static bool cpt = false;
    static Engine::UiWindow *win = new Engine::MainMenuBar();

    if (cpt == false)
    {
        Engine::Menu menu("Fichiers");
        std::shared_ptr<Engine::UiWindow> Mmenu = std::make_shared<Engine::Menu>(menu);

        auto i1 = std::make_shared<Engine::WMenuItem>("File", "CTRL+N");
        auto i2 = std::make_shared<Engine::WMenuItem>("Create");
        auto i3 = std::make_shared<Engine::WMenuItem>("Open", "CTRL+O");
        auto i4 = std::make_shared<Engine::WMenuItem>("Open as Layers", "CTRL+ALT+O");
        auto i5 = std::make_shared<Engine::WMenuItem>("Open Location");

        Mmenu->addWidget(i1);
        Mmenu->addWidget(i2);
        Mmenu->addWidget(i3);
        Mmenu->addWidget(i4);
        Mmenu->addWidget(i5);

        win->addWindow(Mmenu);

        cpt = !cpt;
    }
    win->render();
}
