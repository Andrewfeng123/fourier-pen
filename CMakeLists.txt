cmake_minimum_required(VERSION 3.10)

# set the project name
project(fourier-pen)

# add the executable
add_executable(main src/Test.cpp)

find_package(SDL2 CONFIG REQUIRED)
target_link_libraries(main PRIVATE SDL2::SDL2 SDL2::SDL2main)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)