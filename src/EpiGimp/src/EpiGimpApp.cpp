/*
** EpiGimp Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include <imgui.h>

#include "EpiGimpApp.hpp"

usa::EpiGimpApp::EpiGimpApp(int ac, char **av) : Application{ac, av} { }

auto usa::EpiGimpApp::init() -> void { }

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
}
