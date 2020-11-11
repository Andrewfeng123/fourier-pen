mkdir build
cd build
call cmake .. "-DCMAKE_TOOLCHAIN_FILE=..\vcpkg\scripts\buildsystems\vcpkg.cmake"
call cmake --build .
cd ..