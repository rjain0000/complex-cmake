cmake_minimum_required(VERSION 3.9)
project(hello VERSION 1.0.1 DESCRIPTION "hello project")


# find_library(HELLO_LIB libhellolib.so)
# message(STATUS ${HELLO_LIB})

include(GNUInstallDirs)
include_directories(${hellolib_INCLUDE_DIRS})
include_directories(${hello2lib_INCLUDE_DIRS})

add_executable(hello src/hello_main.c)
target_link_libraries(${PROJECT_NAME} PRIVATE hellolib hello2lib)


################################
# Add gtest environment
################################
# enable_testing()
# find_package(GTest REQUIRED)
# # add gtest include directory: way 1
# include_directories(${GTest_INCLUDE_DIRS})
# # add gtest include directory: way 2
# #include_directories(${GTest_SOURCE_DIRS}/include ${GTest_SOURCE_DIR})

# ################################
# # Build tests
# ################################
# aux_source_directory(./test DIR_TEST_SRCS)
# add_executable(libhelloTest ${DIR_TEST_SRCS})

# # parameter `gtest` should at the front of `pthread`
# target_link_libraries(libhelloTest gtest pthread hellolib)

# # Take all gtest cases as one Cmake test case
# add_test(AllLibHelloTest libhelloTest)