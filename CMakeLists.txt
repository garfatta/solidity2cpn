# Specify the minimum version for CMake
cmake_minimum_required(VERSION 3.12.0)

# Project information
project(solidity2CPN CXX)

# C++11 required
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Third-party libraries PATH
set(THIRD_PARTY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/third-party)

# JSON library
add_library(json INTERFACE)
target_include_directories(json INTERFACE "${THIRD_PARTY_INCLUDE_DIR}/nlohmann")

# CLI library
add_library(cli11 INTERFACE)
target_include_directories(cli11 INTERFACE "${THIRD_PARTY_INCLUDE_DIR}/cli11")

# Source folder
add_subdirectory(src)

# The executable code is here
add_subdirectory(app)
