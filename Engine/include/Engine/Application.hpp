/*
** EpiGimp Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

// TODO: Remove this
#include <json.hpp>
using Json = nlohmann::json;

#include <cstdint>
#include <memory>

namespace Engine {
    class Application {
    private:
        sf::Text m_textFPS{};
    protected:
        std::unique_ptr<sf::RenderWindow> m_window{nullptr};

        uint32_t m_fps{0};
        double m_deltaTime{0.0};
    public:
        static sf::Font DefaultFont;

        Application(int ac, char **av);
        virtual ~Application() = default;

        void start(const char *title);
        void drawFps();

        virtual void processEvent(const sf::Event &event);

        virtual void init() = 0;
        virtual void deinit() = 0;
        virtual void tick(double deltaTime) = 0;
        virtual void draw() = 0;
    };
}
