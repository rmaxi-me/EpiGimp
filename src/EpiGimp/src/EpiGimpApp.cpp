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

//auto usa::EpiGimpApp::drawFileMenu() -> void
//{
//    if (ImGui::BeginMenu("Menu"))
//    {
//        ImGui::MenuItem("File", "CTRL+N");
//        ImGui::MenuItem("Create");
//        ImGui::MenuItem("Open", "CTRL+O");
//        ImGui::MenuItem("Open as Layers", "CTRL+ALT+O");
//        ImGui::MenuItem("Open Location");
//        ImGui::MenuItem("Open Recent");
//        ImGui::Separator();
//        ImGui::MenuItem("Save", "CTRL+S");
//        ImGui::MenuItem("Save As...", "Shift+CTRL+S");
//        ImGui::MenuItem("Save a Copy");
//        ImGui::MenuItem("Revert");
//        ImGui::Separator();
//        ImGui::MenuItem("Export");
//        ImGui::MenuItem("Export As");
//        ImGui::MenuItem("Properties");
//        ImGui::Separator();
//        ImGui::MenuItem("Close View", "CTRL+W");
//        ImGui::MenuItem("Close all", "Shift+CTRL+W");
//        ImGui::MenuItem("Quit", "CTRL+Q");
//        ImGui::EndMenu();
//    }
//}
//
//auto usa::EpiGimpApp::drawEditMenu() -> void
//{
//    if (ImGui::BeginMenu("Edit"))
//    {
//        ImGui::MenuItem("Undo", "CTRL+Z");
//        ImGui::MenuItem("Redo", "CTRL+Y");
//        ImGui::MenuItem("Fade");
//        ImGui::MenuItem("Undo History");
//        ImGui::Separator();
//        ImGui::MenuItem("Cut", "CTRL+X");
//        ImGui::MenuItem("Copy", "CTRL+C");
//        ImGui::MenuItem("Copy Visible", "Shift+CTRL+C");
//        ImGui::MenuItem("Paste", "CTRL+V");
//        ImGui::MenuItem("Paste Into");
//        ImGui::MenuItem("Past As");
//        ImGui::MenuItem("Buffer");
//        ImGui::Separator();
//        ImGui::MenuItem("Clear");
//        ImGui::EndMenu();
//    }
//}
//
//auto usa::EpiGimpApp::drawSelectMenu() -> void
//{
//    if (ImGui::BeginMenu("Select"))
//    {
//        ImGui::MenuItem("All", "CTRL+A");
//        ImGui::MenuItem("None", "Shift+CTRL+A");
//        ImGui::MenuItem("Invert", "CTRL+I");
//        ImGui::MenuItem("Float", "Shift+CTRL+L");
//        ImGui::MenuItem("By Color", "Shift+O");
//        ImGui::MenuItem("From Path", "Shift+V");
//        ImGui::EndMenu();
//    }
//}
//
//auto usa::EpiGimpApp::drawViewMenu() -> void
//{
//    if (ImGui::BeginMenu("View"))
//    {
//        ImGui::MenuItem("Zoom");
//        ImGui::MenuItem("Fullscreen", "F11");
//        ImGui::Separator();
//        ImGui::MenuItem("Show Grid");
//        ImGui::EndMenu();
//    }
//}
//
//auto usa::EpiGimpApp::drawImageMenu() -> void
//{
//    if (ImGui::BeginMenu("Image"))
//    {
//        ImGui::MenuItem("Duplicate", "CTRL+D");
//        ImGui::MenuItem("Mode");
//        ImGui::MenuItem("Transform");
//        ImGui::MenuItem("Canvas Size");
//        ImGui::MenuItem("None");
//        ImGui::EndMenu();
//    }
//}
//
//auto usa::EpiGimpApp::drawLayerMenu() -> void
//{
//    if (ImGui::BeginMenu("Layer"))
//    {
//        ImGui::MenuItem("New Layer", "Shift+CTRL+N");
//        ImGui::MenuItem("New From Visible");
//        ImGui::MenuItem("New Layer Group");
//        ImGui::MenuItem("Duplicate Layer", "Shift+CTRL+D");
//        ImGui::MenuItem("Anchor Layer", "CTRL+H");
//        ImGui::MenuItem("Merge Down");
//        ImGui::MenuItem("Merge Up");
//        ImGui::EndMenu();
//    }
//}
//
//auto usa::EpiGimpApp::drawColorMenu() -> void
//{
//    if (ImGui::BeginMenu("Color"))
//    {
//        ImGui::MenuItem("Color Balance");
//        ImGui::MenuItem("Hue-Saturation");
//        ImGui::MenuItem("Colorize");
//        ImGui::MenuItem("Brightness-Contrast");
//        ImGui::MenuItem("Threshold");
//        ImGui::MenuItem("Levels");
//        ImGui::MenuItem("Desaturate");
//        ImGui::EndMenu();
//    }
//}
//
//auto usa::EpiGimpApp::drawFiltersMenu() -> void
//{
//    if (ImGui::BeginMenu("Filters"))
//    {
//        ImGui::MenuItem("Blur");
//        ImGui::MenuItem("...");
//        ImGui::EndMenu();
//    }
//}
//
//auto usa::EpiGimpApp::drawWindowsMenu() -> void
//{
//    if (ImGui::BeginMenu("Windows"))
//    {
//        ImGui::MenuItem("ToolBox", "CTRL+B");
//        ImGui::MenuItem("Hide Docks", "TAB");
//        ImGui::EndMenu();
//    }
//}
//
//auto usa::EpiGimpApp::drawMainMenuBar() -> void
//{
//    if (ImGui::BeginMainMenuBar())
//    {
//        drawFileMenu();
//        drawEditMenu();
//        drawSelectMenu();
//        drawViewMenu();
//        drawImageMenu();
//        drawLayerMenu();
//        drawColorMenu();
//        drawFiltersMenu();
//        drawWindowsMenu();
//        ImGui::EndMainMenuBar();
//    }
//}

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
