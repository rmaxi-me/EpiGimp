function(enable_doxygen)
    option(ENABLE_DOXYGEN "Enable doxygen doc builds of source" OFF)
    if(ENABLE_DOXYGEN)
        set(DOXYGEN_CALLER_GRAPH ON)
        set(DOXYGEN_CALL_GRAPH ON)
        set(DOXYGEN_EXTRACT_ALL ON)
        find_package(Doxygen REQUIRED dot)

        if(NOT DOXYGEN_FOUND)
            message(FATAL_ERROR "Doxygen need to be installed to generate the doxygen documentation")
        endif()

        configure_file(
            ${CMAKE_SOURCE_DIR}/Documentation/Doxyfile.in
            ${CMAKE_BINARY_DIR}/Documentation/Doxyfile
            @ONLY)

        configure_file(
            ${CMAKE_SOURCE_DIR}/Documentation/ExtraPages.hpp.in
            ${CMAKE_BINARY_DIR}/Documentation/ExtraPages.hpp
            @ONLY)

        find_program(CONAN_CMD conan)

        if(NOT CONAN_CMD)
            message(FATAL_ERROR "Conan executable not found!")
        endif()

        add_custom_target(conan_doc ALL
            COMMAND ${CONAN_CMD} info ${CMAKE_SOURCE_DIR}
                --graph=${CMAKE_BINARY_DIR}/Documentation/package.html
            COMMENT "Generating Package documentation with Conan"
            VERBATIM)

#        doxygen_add_docs(doxygen-docs ${PROJECT_SOURCE_DIR})

        add_custom_target(doc_doxygen ALL
            COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_BINARY_DIR}/Documentation/Doxyfile
                WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
            COMMENT "Generating API documentation with Doxygen"
            DEPENDS conan_doc
            VERBATIM)

    endif()
endfunction()
