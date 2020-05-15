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
    auto saveAsPopup() -> bool;
    auto drawErrorDialog() -> void;
private:
    bool m_saveAsDialog = false;
    bool m_saved = false;
    char buff[255]{};

    bool m_errorDialog = false;    
};
