cmake_minimum_required(VERSION 3.0.0)
project(Vc_example VERSION 0.1.0)

add_executable(Vc_example src/main.cpp)

find_package(unofficial-box2d CONFIG REQUIRED)
find_package(SFML COMPONENTS graphics window system)

target_link_libraries(Vc_example PRIVATE unofficial::box2d::box2d)
target_link_libraries(Vc_example PRIVATE X11 FLAC UDev OpenAL)
target_link_libraries(Vc_example PRIVATE -lsfml-graphics -lsfml-window -lsfml-system)
