
# foreach(file ${tests})
#   set(name)
#   get_filename_component(name ${file} NAME_WE)
#   add_executable("${name}_tests"
#     ${sources}
#     ${file}
#     "${PROJECT_SOURCE_DIR}/test/main.cpp")
#   target_link_libraries("${name}_tests" gtest pthread gtest_main)
#   add_test(NAME ${name} COMMAND "${name}_tests")

# endforeach()