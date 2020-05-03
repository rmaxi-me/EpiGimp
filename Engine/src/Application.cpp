/*
** EpiGimp Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include <SFML/Window/Event.hpp>

#include <chrono>
#include <sstream>

#include "Engine/Application.hpp"

using namespace std::chrono_literals;

static inline sf::Font loadDefaultFont()
{
    sf::Font font;

    font.loadFromFile("Resources/JetBrainsMono-Regular.ttf");
    return font;
}

sf::Font Engine::Application::DefaultFont{loadDefaultFont()};

Engine::Application::Application(int ac, char **av)
{
    // TODO: Argument parsing lib
    (void) ac;
    (void) av;

    m_textFPS.setFont(DefaultFont);
    m_textFPS.setCharacterSize(20);
    m_textFPS.setString("...");
    m_textFPS.setFillColor(sf::Color::Yellow);
    m_textFPS.setPosition(5, 5);
}

void Engine::Application::processEvent(const sf::Event &event)
{
    switch (event.type) {
    case sf::Event::EventType::Closed:
        m_window->close();
        break;
    default:
        break;
    }
}

void Engine::Application::start(const char *title)
{
    sf::Event event{};
    m_window = std::make_unique<sf::RenderWindow>(sf::VideoMode{1600, 900}, title, sf::Style::Close);

    auto frameCount = m_fps;
    auto previous = std::chrono::high_resolution_clock::now();
    decltype(previous) now;

    init();
    while (m_window->isOpen()) {
        m_window->clear();

        while (m_window->pollEvent(event))
            processEvent(event);

        tick(m_deltaTime);

        draw();
        drawFps();
        m_window->display();

        ++frameCount;
        now = std::chrono::high_resolution_clock::now();
        if (std::chrono::duration_cast<std::chrono::seconds>(now - previous) >= 1s) {
            m_fps = frameCount;
            frameCount = 0;
            previous = now;
        }
    }
    deinit();
}

void Engine::Application::drawFps()
{
    std::ostringstream oss{};

    oss << m_fps << " FPS";
    m_textFPS.setString(oss.str());

    m_window->draw(m_textFPS);
}
