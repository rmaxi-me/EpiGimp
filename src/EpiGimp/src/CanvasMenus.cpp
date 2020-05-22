/*
** EpiGimp Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include <imgui.h>
#include <iostream>
#include <cstring>
#include "CanvasMenus.hpp"


auto CanvasMenus::drawFileMenu() -> void
{
    if (ImGui::BeginMenu("Menu")) {
        ImGui::MenuItem("File", "CTRL+N");
        ImGui::MenuItem("Create");
        if (ImGui::MenuItem("Open", "CTRL+O"))
        {
            m_openDialog = true;
        }
        ImGui::MenuItem("Open as Layers", "CTRL+ALT+O");
        ImGui::MenuItem("Open Recent");
        ImGui::Separator();
        ImGui::MenuItem("Save", "CTRL+S");
        if (ImGui::MenuItem("Save As...", "Shift+CTRL+S"))
        {
            m_saveAsDialog = true;
        }
        ImGui::MenuItem("Save a Copy");
        ImGui::MenuItem("Revert");
        ImGui::Separator();
        ImGui::MenuItem("Export");
        if (ImGui::MenuItem("Export As"))
        {
            m_exportAsDialog = true;
        }
        ImGui::MenuItem("Properties");
        ImGui::Separator();
        ImGui::MenuItem("Close View", "CTRL+W");
        ImGui::MenuItem("Close all", "Shift+CTRL+W");
        ImGui::MenuItem("Quit", "CTRL+Q");
        ImGui::EndMenu();
    }
}

auto CanvasMenus::drawEditMenu() -> void
{
    if (ImGui::BeginMenu("Edit")) {
        ImGui::MenuItem("Undo", "CTRL+Z");
        ImGui::MenuItem("Redo", "CTRL+Y");
        ImGui::MenuItem("Fade");
        ImGui::MenuItem("Undo History");
        ImGui::Separator();
        ImGui::MenuItem("Cut", "CTRL+X");
        ImGui::MenuItem("Copy", "CTRL+C");
        ImGui::MenuItem("Copy Visible", "Shift+CTRL+C");
        ImGui::MenuItem("Paste", "CTRL+V");
        ImGui::MenuItem("Paste Into");
        ImGui::MenuItem("Past As");
        ImGui::MenuItem("Buffer");
        ImGui::Separator();
        ImGui::MenuItem("Clear");
        ImGui::EndMenu();
    }
}

auto CanvasMenus::drawSelectMenu() -> void
{
    if (ImGui::BeginMenu("Select")) {
        ImGui::MenuItem("All", "CTRL+A");
        ImGui::MenuItem("None", "Shift+CTRL+A");
        ImGui::MenuItem("Invert", "CTRL+I");
        ImGui::MenuItem("Float", "Shift+CTRL+L");
        ImGui::MenuItem("By Color", "Shift+O");
        ImGui::MenuItem("From Path", "Shift+V");
        ImGui::EndMenu();
    }
}

auto CanvasMenus::drawViewMenu() -> void
{
    if (ImGui::BeginMenu("View")) {
        ImGui::MenuItem("Zoom");
        ImGui::MenuItem("Fullscreen", "F11");
        ImGui::Separator();
        ImGui::MenuItem("Show Grid");
        ImGui::EndMenu();
    }
}

auto CanvasMenus::drawImageMenu() -> void
{
    if (ImGui::BeginMenu("Image")) {
        ImGui::MenuItem("Duplicate", "CTRL+D");
        ImGui::MenuItem("Mode");
        ImGui::MenuItem("Transform");
        ImGui::MenuItem("Canvas Size");
        ImGui::MenuItem("None");
        ImGui::EndMenu();
    }
}

auto CanvasMenus::drawLayerMenu() -> void
{
    if (ImGui::BeginMenu("Layer")) {
        ImGui::MenuItem("New Layer", "Shift+CTRL+N");
        ImGui::MenuItem("New From Visible");
        ImGui::MenuItem("New Layer Group");
        ImGui::MenuItem("Duplicate Layer", "Shift+CTRL+D");
        ImGui::MenuItem("Anchor Layer", "CTRL+H");
        ImGui::MenuItem("Merge Down");
        ImGui::MenuItem("Merge Up");
        ImGui::EndMenu();
    }
}

auto CanvasMenus::drawColorMenu() -> void
{
    if (ImGui::BeginMenu("Color")) {
        ImGui::MenuItem("Color Balance");
        ImGui::MenuItem("Hue-Saturation");
        ImGui::MenuItem("Colorize");
        ImGui::MenuItem("Brightness-Contrast");
        ImGui::MenuItem("Threshold");
        ImGui::MenuItem("Levels");
        ImGui::MenuItem("Desaturate");
        ImGui::EndMenu();
    }
}

auto CanvasMenus::drawFiltersMenu() -> void
{
    if (ImGui::BeginMenu("Filters")) {
        ImGui::MenuItem("Blur");
        ImGui::MenuItem("...");
        ImGui::EndMenu();
    }
}

auto CanvasMenus::drawWindowsMenu() -> void
{
    if (ImGui::BeginMenu("Windows")) {
        ImGui::MenuItem("ToolBox", "CTRL+B");
        ImGui::MenuItem("Hide Docks", "TAB");
        ImGui::EndMenu();
    }
}

auto CanvasMenus::exportAsPopup() -> bool
{
    static bool asExport = false;

    if (m_exportAsDialog)
    {
        ImGui::OpenPopup("ExportAsDialog");
    }

    if (ImGui::BeginPopupModal("ExportAsDialog"))
    {
        ImGui::Text("Export As ...\n\n");

        ImGui::InputTextWithHint("###ExportAsInput", "File location ...", buffExp, 255, 0);
        ImGui::Separator();
        if (ImGui::Button("OK", ImVec2(120, 0))) {
            ImGui::CloseCurrentPopup();
            m_exportAsDialog = false;
            asExport = true;
            m_exported = true;
        }
        ImGui::SetItemDefaultFocus();
        ImGui::SameLine();
        if (ImGui::Button("Cancel", ImVec2(120, 0))) {
            ImGui::CloseCurrentPopup();
            m_exportAsDialog = false;
            asExport = false;
        }
    }
    return asExport;
}

auto CanvasMenus::drawSaveDialog() -> bool
{
    static bool asSave = false;

    if (m_saveAsDialog)
    {
        ImGui::OpenPopup("saveAsDialog");
    }

    if (ImGui::BeginPopupModal("saveAsDialog"))
    {
        ImGui::Text("Save As ...\n\n");

        ImGui::InputTextWithHint("###SaveAsInput", "File location ...", buffSave, 255, 0);
        ImGui::Separator();
        if (ImGui::Button("OK", ImVec2(120, 0))) {
            ImGui::CloseCurrentPopup();
            m_saveAsDialog = false;
            asSave = true;
            m_save = true;
        }
        ImGui::SetItemDefaultFocus();
        ImGui::SameLine();
        if (ImGui::Button("Cancel", ImVec2(120, 0))) {
            ImGui::CloseCurrentPopup();
            m_saveAsDialog = false;
            asSave = false;
        }
    }
    return asSave;
}

auto CanvasMenus::drawOpenDialog() -> bool
{
    static bool asOpen = false;

    if (m_openDialog)
    {
        ImGui::OpenPopup("OpenDialog");
    }

    if (ImGui::BeginPopupModal("OpenDialog"))
    {
        ImGui::Text("Open ...\n\n");

        ImGui::InputTextWithHint("###OpenInput", "File location ...", buffOpen, 255, 0);
        ImGui::Separator();
        if (ImGui::Button("OK", ImVec2(120, 0))) {
            ImGui::CloseCurrentPopup();
            m_openDialog = false;
            asOpen = true;
            m_open = true;
        }
        ImGui::SetItemDefaultFocus();
        ImGui::SameLine();
        if (ImGui::Button("Cancel", ImVec2(120, 0))) {
            ImGui::CloseCurrentPopup();
            m_openDialog = false;
            m_open = false;
        }
    }
    return asOpen;
}

auto CanvasMenus::getOpenPath() -> std::string
{
    if (!m_open)
        return "";
    m_open = false;
    std::string path(buffOpen);
    std::memset(buffOpen, 0, sizeof(buffOpen));
    return path;
}

auto CanvasMenus::getSavePath() -> std::string
{
    if (!m_save)
        return "";
    m_save = false;
    std::string path(buffSave);
    std::memset(buffSave, 0, sizeof(buffSave));
    return path;
}

auto CanvasMenus::getExportPath() -> std::string
{
    if (!m_exported)
        return "";
    m_exported = false;
    std::string path(buffExp);
    std::memset(buffExp, 0, sizeof(buffExp));
    return path;
}

auto CanvasMenus::enableErrorDialog() -> void
{
    m_errorDialog = true;
}

auto CanvasMenus::drawErrorDialog() -> void
{
    if (m_errorDialog)
    {
        ImGui::OpenPopup("ErrorDialog");
    }

    if (ImGui::BeginPopupModal("ErrorDialog"))
    {
        ImGui::Text("Error Occured");

        ImGui::Separator();
        if (ImGui::Button("OK", ImVec2(120, 0))) {
            ImGui::CloseCurrentPopup();
            m_errorDialog = false;
        }
    }
}

auto CanvasMenus::save(std::vector<Layer> &layers, const std::string &path) -> bool
{
    std::cout << "INFO : saving..." << std::endl;
    std::FILE *outfile = std::fopen(path.c_str(), "w");
    auto nbrLayer = layers.size();
    size sizeLayer[nbrLayer];
    std::memset(sizeLayer, 0, nbrLayer*sizeof(size));

    if (outfile == nullptr)
        return false;

    for (long unsigned int i = 0; i < nbrLayer; ++i)
        sizeLayer[i] = {layers[i].image.getSize().x, layers[i].image.getSize().y};
    
    std::fwrite(&nbrLayer, sizeof(nbrLayer), 1, outfile);
    std::fwrite(&sizeLayer, sizeof(sizeLayer), 1, outfile);

    for (auto &i : layers)
    {
        const sf::Uint8 *data = i.image.getPixelsPtr();
        sf::Uint8 arrayDataPixel[i.image.getSize().x * i.image.getSize().y * 4];
        std::memset(arrayDataPixel, 0, i.image.getSize().x * i.image.getSize().y * 4*sizeof(sf::Uint8));
        for (size_t j = 0; j < i.image.getSize().x * i.image.getSize().y * 4; j++)
            arrayDataPixel[j] = data[j];
        std::fwrite(arrayDataPixel, sizeof(arrayDataPixel), 1, outfile);
    }
    return true;  
}

auto CanvasMenus::generateImage(FILE *infile, size sizeLayer) -> sf::Image
{
    sf::Image bckImage;

    sf::Uint8 arrayDataPixel[sizeLayer.x * sizeLayer.y * 4];
    std::memset( arrayDataPixel, 0, sizeLayer.x * sizeLayer.y * 4*sizeof(sf::Uint8) );

    [[maybe_unused]]auto ret = std::fread(arrayDataPixel, sizeof(arrayDataPixel), 1, infile);

    bckImage.create(sizeLayer.x, sizeLayer.y);

    for (uint i = 0; i < sizeLayer.x; ++i)
    {
        for (uint j = 0; j < sizeLayer.x; j++)
        {
            sf::Uint8 r = arrayDataPixel[(i + j * sizeLayer.x) * 4 + 0];
            sf::Uint8 g = arrayDataPixel[(i + j * sizeLayer.x) * 4 + 1];
            sf::Uint8 b = arrayDataPixel[(i + j * sizeLayer.x) * 4 + 2];
            sf::Uint8 a = arrayDataPixel[(i + j * sizeLayer.x) * 4 + 3];
            bckImage.setPixel(i, j, sf::Color(r, g, b, a));
        }
    }
    return bckImage;
}

auto CanvasMenus::open(std::vector<Layer> &layers, const std::string &path) -> bool
{
    std::cout << "INFO : opening..." << std::endl;
    std::FILE *infile = std::fopen(path.c_str(), "r");
    long unsigned int nbrLayer = 0;

    if (infile == nullptr)
        return false;

    if (std::fread(&nbrLayer, sizeof(nbrLayer), 1, infile) == 0)
        return false;

    size sizeLayer[nbrLayer];
    std::memset(sizeLayer, 0, nbrLayer*sizeof(size));
    if (std::fread(&sizeLayer, sizeof(sizeLayer), 1, infile) == 0)
        return false;


    layers.clear();
    for (long unsigned int i = 0; i < nbrLayer; i++)
        layers.push_back(generateImage(infile, sizeLayer[i]));

    std::fclose(infile);
    std::cout << "INFO : Done" << std::endl;
    return true;
}

auto CanvasMenus::drawMainMenuBar() -> void
{
    if (ImGui::BeginMainMenuBar()) {
        drawFileMenu();
        drawEditMenu();
        drawSelectMenu();
        drawViewMenu();
        drawImageMenu();
        drawLayerMenu();
        drawColorMenu();
        drawFiltersMenu();
        drawWindowsMenu();
        ImGui::EndMainMenuBar();
    }
    exportAsPopup();
    drawSaveDialog();
    drawOpenDialog();
    drawErrorDialog();
}

