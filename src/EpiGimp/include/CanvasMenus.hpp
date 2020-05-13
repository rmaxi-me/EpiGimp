/*
** EpiGimp Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#pragma once

class CanvasMenus {
public:
    static auto drawMainMenuBar() -> void;
private:
    static auto drawFileMenu() -> void;
    static auto drawEditMenu() -> void;
    static auto drawSelectMenu() -> void;
    static auto drawViewMenu() -> void;
    static auto drawImageMenu() -> void;
    static auto drawLayerMenu() -> void;
    static auto drawColorMenu() -> void;
    static auto drawFiltersMenu() -> void;
    static auto drawWindowsMenu() -> void;
};
