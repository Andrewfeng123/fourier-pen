@echo off
if exist ".\build\" (rm -rf build)
mkdir build
cd build
call cmake .. "-DCMAKE_TOOLCHAIN_FILE=..\vcpkg\scripts\buildsystems\vcpkg.cmake" > cmake_outputs
call cmake --build .
cd ..
echo build done