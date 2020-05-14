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
        src/Tools/MoveLayer.cpp include/Tools/MoveLayer.hpp src/Layer.cpp include/Layer.hpp src/Tools/ABrush.cpp include/Tools/ABrush.hpp src/Tools/Eraser.cpp include/Tools/Eraser.hpp src/Tools/Pencil.cpp include/Tools/Pencil.hpp)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../Engine/include)
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}Engine)
