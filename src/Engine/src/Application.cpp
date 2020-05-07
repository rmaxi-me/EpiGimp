/*
** EpiGimp Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include <chrono>
#include <sstream>
#include <iostream>

#include <imgui-SFML.h>

#include <SFML/Window/Event.hpp>

#include <Config/Definitions.hpp>

#include "Engine/Application.hpp"

using namespace std::chrono_literals;

template<typename T>
static inline auto load(const std::string_view path) -> T
{
    T resource;
    resource.loadFromFile(path.data());
    return resource;
}

sf::Font usa::Engine::Application::DefaultFont{load<sf::Font>("Resources/Font/JetBrainsMono-Regular.ttf")};

// TODO: Argument parsing lib
usa::Engine::Application::Application(int, char **)
{
    std::cout << PROJECT_NAME << "\\" << PROJECT_VERSION << '\n' << PROJECT_BUILD_TYPE_AS_STRING << '\n';

    m_textFPS.setFont(DefaultFont);
    m_textFPS.setCharacterSize(20);
    m_textFPS.setString("...");
    m_textFPS.setFillColor(sf::Color::Yellow);
    m_textFPS.setPosition(5, 5);
}

auto usa::Engine::Application::processEvent(const sf::Event &event) -> void
{
    ImGui::SFML::ProcessEvent(event);

    switch (event.type) {
    case sf::Event::EventType::Closed: m_window.close(); break;
    default: break;
    }
}

auto usa::Engine::Application::start(const std::string_view &title) -> void
{
    sf::Event event{};
    m_window.create(sf::VideoMode{1200, 675}, title.data(), sf::Style::Close);

    auto frameCount = m_fps;
    auto previous = std::chrono::high_resolution_clock::now();
    decltype(previous) now;
    sf::Clock clock{};

    ImGui::SFML::Init(m_window);
    init();
    while (m_window.isOpen()) {
        m_window.clear();

        while (m_window.pollEvent(event)) processEvent(event);

        ImGui::SFML::Update(m_window, m_deltaTime);
        tick(m_deltaTime.asSeconds());

        draw();
        ImGui::SFML::Render(m_window);
        drawFps();
        m_window.display();

        ++frameCount;
        now = std::chrono::high_resolution_clock::now();
        if (std::chrono::duration_cast<std::chrono::seconds>(now - previous) >= 1s) {
            m_fps = frameCount;
            frameCount = 0;
            previous = now;
        }

        m_deltaTime = clock.restart();
    }
    deinit();
    ImGui::SFML::Shutdown();
}

auto usa::Engine::Application::drawFps() -> void
{
    std::ostringstream oss{};

    oss << m_fps << " FPS";
    m_textFPS.setString(oss.str());

    m_window.draw(m_textFPS);
}
