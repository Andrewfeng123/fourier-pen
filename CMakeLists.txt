cmake_minimum_required(VERSION 3.10)

# set the project name
project(fourier-pen)

# add the executable
add_executable(main src/main.cpp)

# add glad library
add_library("glad" "src/include/glad/glad.c")
include_directories("src/include")

find_package(SDL2 CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(OpenGL REQUIRED)

target_link_libraries(main PRIVATE 
    SDL2::SDL2
    SDL2::SDL2main
    "glad"
    imgui::imgui
    )

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)