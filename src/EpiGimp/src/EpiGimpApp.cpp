/*
** EpiGimp Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include <imgui.h>

#include "EpiGimpApp.hpp"
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

auto usa::EpiGimpApp::init() -> void
{
    if (m_arguments.empty()) {
        createScene<SceneCanvas>(800, 800);
    } else {
        if (m_arguments.size() >= 2)
            std::cerr << "warning: opening multiple files is not supported yet\n";
        createScene<SceneCanvas>(m_arguments[0]);
    }
}

auto usa::EpiGimpApp::deinit() -> void { }

auto usa::EpiGimpApp::tick(float) -> void { }

auto usa::EpiGimpApp::draw() -> void
{
    ImGui::Begin("Test window");
    {
        ImGui::Text("Hello world!");
        ImGui::Button("> Useless button <");
    }
    ImGui::End();

    ImGui::Begin("Second Window");
    {
        static float color[4];
        ImGui::ColorPicker4("Color picker", color);
        ImGui::Button("> Useless button <");
    }
    ImGui::End();
}
