cmake_minimum_required(VERSION 3.9)

project(hello VERSION 1.0.1 DESCRIPTION "master project")

set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)
set(CMAKE_DISABLE_SOURCE_CHANGES  ON)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/scripts/cmake)

if (CMAKE_BUILD_TYPE STREQUAL "Coverage")
    include(CodeCoverage)

    SET(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
    SET(CMAKE_C_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")

endif() #CMAKE_BUILD_TYPE STREQUAL "Coverage"

if ("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
  message(SEND_ERROR "In-source builds are not allowed.")
endif ()

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_COLOR_MAKEFILE   ON)


# When done tweaking common stuff, configure the components (subprojects).
# NOTE: The order matters! The most independent ones should go first.

include(CTest)
enable_testing()

add_subdirectory(libhello) # B is a shared library 
add_subdirectory(libhello2) # B is a shared library 
add_subdirectory(hello) # Executable (depends B)


if (CMAKE_BUILD_TYPE STREQUAL "Coverage")
    setup_target_for_coverage_gcovr_html(
        NAME coverage 
        EXECUTABLE ctest 
        )
ENDIF()

# list all targets.
# cmake --build . --target help