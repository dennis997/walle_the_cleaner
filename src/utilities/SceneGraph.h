#ifndef WALL_E_SCENEGRAPH_H
#define WALL_E_SCENEGRAPH_H

#include "../vendor/glut.h"
#include "../scenes/surface/Ground.h"
#include "../scenes/surface/Surface.h"
#include "../scenes/robot/Robot.h"
#include "../scenes/robot/Body.h"
#include "../scenes/robot/Wheel.h"
#include "../scenes/robot/arm/LowerArm.h"
#include "../scenes/robot/arm/UpperArm.h"
#include "../scenes/robot/Neck.h"
#include "../scenes/robot/Eye.h"
#include "../scenes/sky/Sky.h"
#include "../scenes/sky/Sun.h"
#include "../scenes/surface/TrashCube.h"
#include "../scenes/sky/Wall.h"
#include "../scenes/robot/arm/Finger.h"
#include "../scenes/robot/Carriage.h"

// top level nodes
inline Robot *robot = new Robot;
inline Surface *surface = new Surface(robot);
inline Sky sky;

/**
 * Add shapes to top level nodes or underneath nodes
 */
inline void buildSceneGraph() {
    //surface.add(new TrashCube(5,0.25/2,5));
    surface->add(new Ground);
    surface->createRandomCubes();

    sky.add(new Sun);
    sky.add(new Wall(LEFT));
    sky.add(new Wall(RIGHT));
    sky.add(new Wall(BACK));
    sky.add(new Wall(FRONT));

    robot->add(new Wheel(Side::LEFT));
    robot->add(new Wheel(Side::RIGHT));

    // right arm
    Body* body = new Body();
    UpperArm* rightUpperArm = new UpperArm(Side::RIGHT);
    LowerArm* rightLowerArm = new LowerArm(Side::RIGHT);
    rightLowerArm->add(new Finger(robot, Side::RIGHT));
    rightUpperArm->add(rightLowerArm);
    body->add(rightUpperArm);

    // left arm
    UpperArm* leftUpperArm = new UpperArm(Side::LEFT);
    LowerArm* leftLowerArm = new LowerArm(Side::LEFT);
    leftLowerArm->add(new Finger(robot, Side::LEFT));
    leftUpperArm->add(leftLowerArm);
    body->add(leftUpperArm);

    // neck and eyes
    Neck* neck = new Neck();
    neck->add(new Eye(Side::LEFT));
    neck->add(new Eye(Side::RIGHT));
    body->add(neck);

    robot->add(body);
    robot->add(new Carriage(robot, surface));
}

/**
 * Prints the three defined top level nodes
 *
 * All added nodes in the buildSceneGraph function will be drawn cascadingly
 */
inline void printSceneGraph(const unsigned int frameIndex) {
    sky.draw(frameIndex);
    surface->draw(frameIndex);
    robot->draw(frameIndex);
}

#endif //WALL_E_SCENEGRAPH_H
