/*
** EpiGimp Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include <chrono>
#include <sstream>
#include <iostream>

#include <imgui.h>
#include <imgui-SFML.h>

#include <SFML/Window/Event.hpp>

#include <Config/Definitions.hpp>

#include "Engine/Application.hpp"

using namespace std::chrono_literals;

// TODO: Argument parsing lib
usa::Engine::Application::Application(int, char **) : m_settings{Settings::fromFile()}
{
    std::cout << PROJECT_NAME << "\\" << PROJECT_VERSION << '\n' << PROJECT_BUILD_TYPE_AS_STRING << '\n';

    m_defaultFont.loadFromFile("Resources/Font/JetBrainsMono-Regular.ttf");
}

usa::Engine::Application::~Application() { m_settings.save(); }

auto usa::Engine::Application::processEvent(const sf::Event &event) -> void
{
    ImGui::SFML::ProcessEvent(event);

    switch (event.type) {
    case sf::Event::EventType::Closed: m_window.close(); break;
    case sf::Event::Resized:
        m_settings.width = event.size.width;
        m_settings.height = event.size.height;
        reloadView();
        break;
    default: break;
    }
}

auto usa::Engine::Application::start(const std::string_view &title) -> void
{
    sf::Event event{};
    sf::Uint32 style = sf::Style::Close;

    style |= m_settings.fullscreen ? sf::Style::Fullscreen : sf::Style::Resize;

    m_window.create(sf::VideoMode{m_settings.width, m_settings.height}, title.data(), style);
    m_window.setFramerateLimit(m_settings.fps_limit);

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
        tick(m_deltaTimeSeconds);

        if (m_scene) {
            m_scene->onTick(m_window, m_deltaTimeSeconds);
            m_scene->onDraw(m_window);
        }

        draw();
        drawFps();
        ImGui::SFML::Render(m_window);
        ImGui::EndFrame();
        m_window.display();

        ++frameCount;
        now = std::chrono::high_resolution_clock::now();
        if (std::chrono::duration_cast<std::chrono::seconds>(now - previous) >= 1s) {
            m_fps = frameCount;
            frameCount = 0;
            previous = now;
        }

        m_deltaTime = clock.restart();
        m_deltaTimeSeconds = m_deltaTime.asSeconds();
    }
    deinit();
    ImGui::SFML::Shutdown();
}

auto usa::Engine::Application::drawFps() const -> void
{
    ImGui::SetNextWindowPos(ImVec2{5, 5});
    ImGui::SetNextWindowSize(ImVec2{0, 0});
    ImGui::Begin("Stats");
    {
        ImGui::BulletText("%u FPS", m_fps);
        ImGui::BulletText("%.6f delta", static_cast<double>(m_deltaTimeSeconds));
    }
    ImGui::End();
}

void usa::Engine::Application::reloadView()
{
    sf::View view = m_window.getView();
    view.reset(sf::FloatRect(0.f, 0.f, static_cast<float>(m_settings.width), static_cast<float>(m_settings.height)));
    view.zoom(m_zoom);
    m_window.setView(view);
}
