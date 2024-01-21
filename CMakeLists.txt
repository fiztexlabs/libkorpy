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

# set(CMAKE_BUILD_TYPE Release)

include(cmake/utils.cmake)
include(GNUInstallDirs)

include(GenerateExportHeader)

add_library(libkorpy SHARED 
    libkorpy/korpy_export.h
    libkorpy/korpy.h
    libkorpy/korpy.cpp
)


# -----------------------------------------
# libkorpy dependencies
# -----------------------------------------

find_package(Python COMPONENTS Interpreter Development REQUIRED)

add_subdirectory(libs/pybind11)

target_link_libraries(libkorpy PRIVATE
    pybind11::embed
)


# -----------------------------------------
# libkorpy target
# -----------------------------------------

target_compile_options(libkorpy PUBLIC "-MT")

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

generate_export_header(libkorpy EXPORT_FILE_NAME "${PROJECT_BINARY_DIR}/korpy_export_shared.h")


