#ifndef WALL_E_SCENEGRAPH_H
#define WALL_E_SCENEGRAPH_H
#include <GL/freeglut.h>
#include <assimp/Importer.hpp>      // C++ importer interface
#include <assimp/scene.h>           // Output data structure
#include <assimp/postprocess.h>     // Post processing flags

#include "../scenes/surface/Ground.h"
#include "../scenes/surface/Surface.h"
#include "../scenes/robot/Robot.h"
#include "../scenes/sky/Sky.h"
#include "../scenes/surface/TrashCube.h"

// top level nodes
Surface surface;
Robot robot;
Sky sky;

// shapes (nodes)
Ground ground;
TrashCube trashCube;

/**
 * Add shapes to top level nodes or underneath nodes
 */
void buildSceneGraph() {
    surface.add(&ground);
    surface.add(&trashCube);

    Assimp

}

/**
 * Prints the three defined top level nodes
 *
 * All added nodes in the buildSceneGraph function will be drawn cascadingly
 */
void printSceneGraph() {
    surface.draw();
    sky.draw();
    robot.draw();
}

#endif //WALL_E_SCENEGRAPH_H
