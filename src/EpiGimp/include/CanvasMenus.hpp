/*
** EpiGimp Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#pragma once

#include <vector>
#include <cstdio>
#include "Layer.hpp"

class CanvasMenus {
public:
    auto drawMainMenuBar() -> void;
    auto getSavePath() -> std::string;
    auto getExportPath() -> std::string;
    auto getOpenPath() -> std::string;
    auto getOpenAsLayerPath() -> std::string;
    auto save(std::vector<Layer> &layers, const std::string &path) -> bool;
    auto open(std::vector<Layer> &layers, const std::string &path) -> bool;
    auto openAsLayer(std::vector<Layer> &layers, const std::string &path) -> bool;
    auto enableErrorDialog() -> void;
    auto create(std::vector<Layer> &layers) -> void;
private:
    struct Size {
        unsigned int x{};
        unsigned int y{};
    };

    auto generateImage(FILE *infile, Size sizeLayer) -> sf::Image;
    auto drawFileMenu() -> void;
    auto drawEditMenu() -> void;
    auto drawSelectMenu() -> void;
    auto drawViewMenu() -> void;
    auto drawImageMenu() -> void;
    auto drawLayerMenu() -> void;
    auto drawColorMenu() -> void;
    auto drawFiltersMenu() -> void;
    auto drawWindowsMenu() -> void;
    auto exportAsPopup() -> bool;
    auto drawErrorDialog() -> void;
    auto drawSaveDialog() -> bool;
    auto drawOpenDialog() -> bool;
    auto drawOpenLayerDialog() -> bool;

private:
    char buffSave[255]{};
    char buffOpen[255]{};
    char buffExp[255]{};
    char buffOpenLayer[255]{};

    bool m_errorDialog = false;

    bool m_exported = false;
    bool m_exportAsDialog = false;

    bool m_save = false;
    bool m_saveAsDialog = false;

    bool m_open = false;
    bool m_openDialog = false;

    bool m_openLayer = false;
    bool m_openDialogLayer = false;
    bool m_create = false;
};
