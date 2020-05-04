macro(run_conan)

if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://github.com/conan-io/cmake-conan/raw/v0.15/conan.cmake"
        "${CMAKE_BINARY_DIR}/conan/conan.cmake")
endif()

include(${CMAKE_BINARY_DIR}/conan/conan.cmake)

conan_add_remote(NAME bincrafters URL https://api.bintray.com/conan/bincrafters/public-conan)

conan_cmake_run(
    CONANFILE conanfile.txt
    REQUIRES ${CONAN_EXTRA_REQUIRES}
    OPTIONS ${CONAN_EXTRA_OPTIONS}
    BASIC_SETUP
    CMAKE_TARGETS # individual targets to link to
    BUILD missing
    NO_OUTPUT_DIRS TARGETS
    INSTALL_ARGS -s build_type=${CMAKE_BUILD_TYPE}
    INSTALL_FOLDER ${CMAKE_BINARY_DIR}/conan
)

endmacro()
