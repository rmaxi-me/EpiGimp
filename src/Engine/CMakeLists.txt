add_library(
        ${PROJECT_NAME}Engine
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Application.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Engine/Application.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Settings/Settings.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Engine/Settings/Settings.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Engine/Utils/Platform.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Engine/Utils/Warnings.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Engine/Json.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Scene.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Engine/Scene.hpp

        ${CMAKE_CURRENT_SOURCE_DIR}/include/Engine/UI/UiWindow.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/UI/UiWindow.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Engine/UI/AWidget.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Engine/UI/Widget/WButton.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/UI/Widget/WButton.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/UI/Window/MainMenuBar.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Engine/UI/Window/MainMenuBar.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/UI/Widget/WMenuItem.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Engine/UI/Widget/WMenuItem.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Engine/UI/Widget/WSeparator.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Engine/UI/Window/Menu.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/UI/Window/Menu.cpp)

find_package(nlohmann_json 3.2.0 REQUIRED)

target_include_directories(${PROJECT_NAME}Engine PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME}Engine PUBLIC project_warnings project_options CONAN_PKG::imgui-sfml
        nlohmann_json::nlohmann_json)
