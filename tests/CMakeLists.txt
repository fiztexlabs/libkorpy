cmake_minimum_required( VERSION 3.20 )

include(cmake/utils.cmake)

add_executable(test-korpy src/korpy-test.cpp)

target_link_libraries(test-korpy libkorpy)

target_include_directories(test-korpy
    PUBLIC
    "libs"
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>")

win_copy_deps_to_target_dir(test-korpy
    libkorpy
)

add_custom_command(TARGET test-korpy POST_BUILD
    COMMAND ${CMAKE_COMMAND} -P "${libkorpy_SOURCE_DIR}/cmake/silent_copy.cmake"
        "${CMAKE_CURRENT_SOURCE_DIR}/data/calc.py" "$<TARGET_FILE_DIR:test-korpy>"
    COMMAND_EXPAND_LISTS)