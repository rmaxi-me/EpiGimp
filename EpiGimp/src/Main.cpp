/*
** EpiGimp Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include <iostream>

#include "EpiGimpApp.hpp"

int main(int ac, char **av)
{
    try {
        EpiGimpApp app{ac, av};

        app.start("EpiGimp");
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
