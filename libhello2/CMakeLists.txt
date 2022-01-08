cmake_minimum_required(VERSION 3.9)
project(hello2lib VERSION 0.0.1 DESCRIPTION "hello2lib description")
include(GNUInstallDirs)
add_library(hello2lib SHARED src/hello2.c)
set_target_properties(hello2lib PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
    PUBLIC_HEADER inc/hello2.h)

target_include_directories(hello2lib PRIVATE ./inc)

# Expose C's public includes (including the ones of C's dependencies transitively)
# to other subprojects through cache variable.
set(${PROJECT_NAME}_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/inc
                                    ${XXX_INCLUDE_DIRS}
    CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)

install(TARGETS hello2lib
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})


################################
# Add coverage environment
################################

# set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/scripts/cmake)

if (CMAKE_BUILD_TYPE STREQUAL "Coverage")
    # include(CodeCoverage)
    setup_target_for_coverage_gcovr_html(
        NAME "${PROJECT_NAME}_coverage"
        EXECUTABLE "${PROJECT_NAME}_tests" 
        BASE_DIRECTORY "${PROJECT_SOURCE_DIR}/src"
        )

    # SET(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
    # SET(CMAKE_C_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")

endif() #CMAKE_BUILD_TYPE STREQUAL "Coverage"
    

################################
# Add gtest environment
################################
enable_testing()
find_package(GTest REQUIRED)
# add gtest include directory: way 1
include_directories(${GTest_INCLUDE_DIRS})
# add gtest include directory: way 2
#include_directories(${GTest_SOURCE_DIRS}/include ${GTest_SOURCE_DIR})
include_directories("${PROJECT_SOURCE_DIR}/inc")

file(GLOB sources "${PROJECT_SOURCE_DIR}/src/*.c")
list(REMOVE_ITEM sources "${PROJECT_SOURCE_DIR}/src/main.c")

file(GLOB tests "${PROJECT_SOURCE_DIR}/test/*.cpp")
# list(REMOVE_ITEM tests "${PROJECT_SOURCE_DIR}/test/main.cpp")

add_executable("${PROJECT_NAME}_tests"
    ${sources}
    ${tests})
target_link_libraries("${PROJECT_NAME}_tests" gtest pthread gtest_main)


add_test(${PROJECT_NAME}_all_tests ${PROJECT_NAME}_tests)


# ################################
# # Build tests
# ################################
# aux_source_directory(./test DIR_TEST_SRCS)
# add_executable(libhelloTest ${DIR_TEST_SRCS})

# # parameter `gtest` should at the front of `pthread`
# target_link_libraries(libhelloTest gtest pthread hello2lib)

# # Take all gtest cases as one Cmake test case
# add_test(AllLibHelloTest libhelloTest)