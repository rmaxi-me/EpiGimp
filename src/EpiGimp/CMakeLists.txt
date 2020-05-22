add_executable(
        ${PROJECT_NAME}
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/EpiGimpApp.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/EpiGimpApp.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/SceneCanvas.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/SceneCanvas.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/CanvasMenus.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/CanvasMenus.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Tools/ATool.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Tools/ATool.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Tools/MoveLayer.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Tools/MoveLayer.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Layer.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Layer.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Tools/ABrush.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Tools/ABrush.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Tools/Eraser.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Tools/Eraser.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Tools/Pencil.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Tools/Pencil.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Tools/Fill.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Tools/Fill.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Tools/ColorPicker.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Tools/ColorPicker.hpp
)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../Engine/include)
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}Engine)
