cmake_minimum_required(VERSION 3.14)
project(Experimental)

include(conan.cmake)
conan_cmake_install(
    BUILD missing
    CONANFILE conanfile.txt
    INSTALL_FOLDER ./conan
    INSTALL_ARGS -s build_type=Debug
)

include(./build/conan/conanbuildinfo.cmake)
conan_basic_setup(NO_OUTPUT_DIRS)

include_directories(${INCLUDE_DIR})

add_executable(app main.cpp)
target_link_libraries(app ${CONAN_LIBS_SFML} ${CONAN_LIBS_BOOST_RANGE})

set_target_properties(app PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ../bin
    CXX_STANDARD 20
)
