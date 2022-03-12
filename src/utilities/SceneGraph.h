#ifndef WALL_E_SCENEGRAPH_H
#define WALL_E_SCENEGRAPH_H

#include "../vendor/glut.h"
#include "../scenes/surface/Ground.h"
#include "../scenes/surface/Surface.h"
#include "../scenes/robot/Robot.h"
#include "../scenes/robot/Body.h"
#include "../scenes/robot/Wheel.h"
#include "../scenes/sky/Sky.h"
#include "../scenes/sky/Sun.h"
#include "../scenes/surface/TrashCube.h"
#include "../scenes/sky/Wall.h"

// top level nodes
inline Surface surface;
inline Robot robot;
inline Sky sky;

/**
 * Add shapes to top level nodes or underneath nodes
 */
inline void buildSceneGraph() {
    surface.add(new TrashCube);
    surface.add(new Ground);


    sky.add(new Sun);
    sky.add(new Wall(LEFT));
    sky.add(new Wall(RIGHT));
    sky.add(new Wall(BACK));
    sky.add(new Wall(FRONT));

    Body* body = new Body();
    body->add(new Wheel(WheelOrientation::LEFT, body->getSize()));
    body->add(new Wheel(WheelOrientation::RIGHT, body->getSize()));
    robot.add(body);
}

/**
 * Prints the three defined top level nodes
 *
 * All added nodes in the buildSceneGraph function will be drawn cascadingly
 */
inline void printSceneGraph(const unsigned int frameIndex) {
    sky.draw(frameIndex);
    surface.draw(frameIndex);
    robot.draw(frameIndex);
}

#endif //WALL_E_SCENEGRAPH_H
