#ifndef WALL_E_SCENEGRAPH_H
#define WALL_E_SCENEGRAPH_H

#include "../vendor/glut.h"
#include "../scenes/surface/Ground.h"
#include "../scenes/surface/Surface.h"
#include "../scenes/robot/Robot.h"
#include "../scenes/sky/Sky.h"
#include "../scenes/sky/Sun.h"
#include "../scenes/surface/TrashCube.h"

// top level nodes
Surface surface;
Robot robot;
Sky sky;

// shapes (nodes)
Ground ground;
TrashCube trashCube;
Sun sun;

/**
 * Add shapes to top level nodes or underneath nodes
 */
void buildSceneGraph() {
    surface.add(&ground);
    surface.add(&trashCube);

    sky.add(&sun);
}

/**
 * Prints the three defined top level nodes
 *
 * All added nodes in the buildSceneGraph function will be drawn cascadingly
 */
void printSceneGraph(const unsigned int frameIndex) {
    surface.draw(frameIndex);
    sky.draw(frameIndex);
    robot.draw(frameIndex);
}

#endif //WALL_E_SCENEGRAPH_H
