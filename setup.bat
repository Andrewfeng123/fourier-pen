git clone https://github.com/microsoft/vcpkg.git
call .\vcpkg\bootstrap-vcpkg.bat
.\vcpkg\vcpkg.exe install sdl2:x64-windows
.\vcpkg\vcpkg.exe install imgui[sdl2-binding]:x64-windows
