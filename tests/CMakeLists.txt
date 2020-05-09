add_subdirectory(unit-test)

if(ENABLE_COVERAGE)
  include(../cmake/CodeCoverage.cmake)
  append_coverage_compiler_flags()

  add_test(NAME tests COMMAND tests)
  add_test(NAME constexpr_tests COMMAND constexpr_tests)
  add_test(NAME relaxed_constexpr_tests COMMAND relaxed_constexpr_tests)

  setup_target_for_coverage_gcovr_html(
    NAME coverage
    EXECUTABLE ctest -j4
    BASE_DIRECTORY unit-test ## : FIXME, it seems that this is not the right path
    # EXCLUDE tests
    DEPENDENCIES tests constexpr_tests relaxed_constexpr_tests)

    add_custom_command(TARGET coverage
        POST_BUILD
        COMMAND cmake -E copy_directory ${CMAKE_BINARY_DIR}/coverage ${CMAKE_SOURCE_DIR}/Documentation/coverage
    )

endif()
