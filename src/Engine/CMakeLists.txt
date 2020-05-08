add_library(${PROJECT_NAME}Engine
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Application.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Engine/Application.hpp
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
    ${CMAKE_CURRENT_SOURCE_DIR}/src/UI/Window/Menu.cpp
)

target_include_directories(${PROJECT_NAME}Engine
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_link_libraries(${PROJECT_NAME}Engine
    PUBLIC project_warnings project_options CONAN_PKG::imgui-sfml
)
