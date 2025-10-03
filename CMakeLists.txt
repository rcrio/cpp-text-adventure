cmake_minimum_required(VERSION 3.10)       # Minimum CMake version
project(TextAdventure VERSION 1.0)         # Project name

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include headers
include_directories(include)

# Add all .cpp files in src + main.cpp
file(GLOB SOURCES "src/*.cpp" "main.cpp")

# Create executable
add_executable(TextAdventure ${SOURCES})