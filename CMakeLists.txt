cmake_minimum_required(VERSION 3.20)
project(
    libkorpy
    VERSION 0.0.1
    DESCRIPTION "Library allows KORSAR execute python files as EVENTs"
    LANGUAGES CXX
)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# -----------------------------------------
# declarations
# -----------------------------------------

set(CMAKE_BUILD_TYPE Release)
# set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MT")

include(cmake/utils.cmake)
include(GNUInstallDirs)

include(GenerateExportHeader)
# set(export_file_name "export_shared.h")

add_library(libkorpy SHARED 
    libkorpy/korpy_export.h
    libkorpy/korpy.h
    libkorpy/korpy.cpp
    # libkorpy/py_to_cpp.cpp
)


# -----------------------------------------
# libkorpy dependencies
# -----------------------------------------

find_package(Python 3.10 COMPONENTS Interpreter Development REQUIRED)

add_subdirectory(libs/pybind11)

# Link alien compiled dll

add_library(alien SHARED IMPORTED)

set_property(TARGET alien PROPERTY
    IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/libs/alien/alien.dll")
set_property(TARGET alien PROPERTY
    IMPORTED_IMPLIB "${CMAKE_SOURCE_DIR}/libs/alien/alien.lib")

generate_export_header(alien EXPORT_FILE_NAME "${PROJECT_BINARY_DIR}/alien_export.h")

target_link_libraries(libkorpy PRIVATE
    pybind11::embed
    alien
)


# -----------------------------------------
# libkorpy target
# -----------------------------------------

# target_compile_definitions(libkorpy 
#     PUBLIC 
#         "<KORPY_STATIC_DEFINE>")

target_include_directories(libkorpy
    PUBLIC
    "libs"
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>")

win_copy_deps_to_target_dir(libkorpy
    pybind11::embed
)

# copy alien library to target dir
add_custom_command(TARGET libkorpy POST_BUILD
    COMMAND ${CMAKE_COMMAND} -P "${libkorpy_SOURCE_DIR}/cmake/silent_copy.cmake"
    "$<TARGET_FILE:alien>" "$<TARGET_FILE_DIR:libkorpy>"
    COMMAND_EXPAND_LISTS)

generate_export_header(libkorpy EXPORT_FILE_NAME "${PROJECT_BINARY_DIR}/korpy_export_shared.h")


