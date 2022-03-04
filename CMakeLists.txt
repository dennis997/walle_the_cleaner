cmake_minimum_required(VERSION 3.21)
project(wall_e)

set(CMAKE_CXX_STANDARD 14)

add_executable(wall_e src/main.cpp
        src/scenes/surface/Surface.cpp
        src/scenes/surface/Ground.cpp
        src/scenes/surface/TrashCube.cpp
        src/scenes/robot/Robot.cpp
        src/scenes/sky/Sky.cpp
        src/model/Scene.cpp
)

target_link_libraries(wall_e -lGLEW)
target_link_libraries(wall_e -lglut)
target_link_libraries(wall_e -lGL)
target_link_libraries(wall_e -lGLU)
target_link_libraries(wall_e -lSOIL)
