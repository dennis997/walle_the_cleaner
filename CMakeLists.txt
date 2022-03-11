cmake_minimum_required(VERSION 3.0)
project(wall_e)

set(CMAKE_CXX_STANDARD 17)

add_executable(wall_e src/main.cpp
        src/scenes/surface/Surface.cpp
        src/scenes/surface/Ground.cpp
        src/scenes/surface/TrashCube.cpp
        src/scenes/robot/Robot.cpp
        src/scenes/robot/Body.cpp
        src/scenes/robot/Wheel.cpp
        src/scenes/sky/Sky.cpp
        src/scenes/sky/Sun.cpp
        src/model/Scene.cpp
        src/model/Handler.cpp
        src/handler/CameraHandler.cpp
        src/handler/RoboterHandler.cpp
)

if (APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -framework GLUT -framework OpenGL")
endif(APPLE)

include(ExternalProject)
set(EXTERNAL_INSTALL_LOCATION ${CMAKE_BINARY_DIR}/external)

ExternalProject_Add(glm
        GIT_REPOSITORY https://github.com/g-truc/glm.git
        CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}
        )

include_directories(${EXTERNAL_INSTALL_LOCATION}/include)
link_directories(${EXTERNAL_INSTALL_LOCATION}/lib)

add_dependencies(wall_e glm)

FILE(COPY res DESTINATION ${CMAKE_BINARY_DIR})

if(UNIX AND NOT APPLE)
    target_link_libraries(wall_e -lglut)
    target_link_libraries(wall_e -lGL)
    target_link_libraries(wall_e -lGLU)
    target_link_libraries(wall_e -lSOIL)
endif(UNIX AND NOT APPLE)
