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

usa::EpiGimpApp::EpiGimpApp(int ac, char **av) :
    Application{ ac, av }
{
}

auto usa::EpiGimpApp::init() -> void
{
    plop.loadFromFile("./red.jpg");
}

auto usa::EpiGimpApp::deinit() -> void
{
}

auto usa::EpiGimpApp::tick(float) -> void
{
}

    //     if (ImGui::BeginMainMenuBar())
    //     {
    //         if (ImGui::BeginMenu("File"))
    //         {
    //             ImGui::EndMenu();
    //         }    override

    //             if (ImGui::MenuItem("Undo", "CTRL+Z"))
    //             {
    //             }
    //             if (ImGui::MenuItem("Redo", "CTRL+Y", false, false))
    //             {
    //             } // Disabled item
    //             ImGui::Separator();
    //             if (ImGui::MenuItem("Cut", "CTRL+X"))
    //             {
    //             }
    //             if (ImGui::MenuItem("Copy", "CTRL+C"))
    //             {
    //             }
    //             if (ImGui::MenuItem("Paste", "CTRL+V"))
    //             {
    //             }
    //             ImGui::EndMenu();
    //         }
    //         ImGui::EndMainMenuBar();
    //     }
    // }
void pute()
{
    std::cout << "pute" << std::endl;
    // if (ImGui::BeginMenu("Menu"))
    // {
            ImGui::MenuItem("File", "CTRL+N");
            ImGui::MenuItem("Create");
            ImGui::MenuItem("Open", "CTRL+O");
            ImGui::MenuItem("Open as Layers", "CTRL+ALT+O");
            ImGui::MenuItem("Open Location");
            ImGui::MenuItem("Open Recent");
            ImGui::Separator();
            ImGui::MenuItem("Save", "CTRL+S");
            ImGui::MenuItem("Save As...", "Shift+CTRL+S");
            ImGui::MenuItem("Save a Copy");
            ImGui::MenuItem("Revert");
            ImGui::Separator();
            ImGui::MenuItem("Export");
            ImGui::MenuItem("Export As");
            ImGui::MenuItem("Properties");
            ImGui::Separator();
            ImGui::MenuItem("Close View", "CTRL+W");
            ImGui::MenuItem("Close all", "Shift+CTRL+W");
            ImGui::MenuItem("Quit", "CTRL+Q");
            // ImGui::Selectable("Demo", &plopi);
            ImGui::EndMenu();
    // }
}

void f1(int, int)
{
    std::cout << "plopiplopi" << std::endl;
}

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
