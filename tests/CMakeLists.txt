message(STATUS "Generating tests")

# Create and link the test executables
add_executable(rag.test_rag src/test_rag.cpp)
target_link_libraries(rag.test_rag rag)

# Test definitions
macro(create_test target)
    add_test(NAME ${target} COMMAND $<TARGET_FILE:${target}>)
endmacro(create_test)

create_test(rag.test_rag)

message(STATUS "Generating tests - done")

# -----------------------------------------------------------------------------
# Code Coverage report
# -----------------------------------------------------------------------------
# cmake .. -DENABLE_COVERAGE=ON
# cmake --build .
# make <target_name>
if (ENABLE_COVERAGE)
    include(CodeCoverage)
    set(COVERAGE_LCOV_EXCLUDES "${CMAKE_CURRENT_SOURCE_DIR}/../libs/*")

    APPEND_COVERAGE_COMPILER_FLAGS()

    include(ProcessorCount)
    ProcessorCount(N_CORES)

    SETUP_TARGET_FOR_COVERAGE_LCOV(
        NAME rag.coverage
        EXECUTABLE cd tests/ && ctest -j ${N_CORES}
        DEPENDENCIES
            rag.test_rag
    )
endif()
