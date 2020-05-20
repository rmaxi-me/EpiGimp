/*
** EpiGimp Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#pragma once

class CanvasMenus {
public:
    auto drawMainMenuBar() -> void;
    auto getSavePath() -> std::string;
    auto getExportPath() -> std::string;
    auto enableErrorDialog() -> void;
private:
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

private:
    char buffSave[255]{};
    char buffExp[255]{};

    bool m_errorDialog = false;
    
    bool m_exported = false;
    bool m_exportAsDialog = false;
    
    bool m_save = false;
    bool m_saveAsDialog = false;
};
