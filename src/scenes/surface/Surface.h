#ifndef WALL_E_SURFACE_H
#define WALL_E_SURFACE_H

#include "../../model/Scene.h"
#include <map>
#include <cmath>
#include <iostream>
#include "TrashCube.h"
#include "../../scenes/robot/Robot.h"
#include "../../utilities/Parameters.h"

/**
 * Includes following scenes:
 * - Ground
 * - TrashCube
 * - ....
 */
class Surface: public Scene {
private:
    std::multimap<float, TrashCube*> trashCubes;
    Robot * robot;
    void calculateDistances();
    float roundoff(float value, unsigned char prec);

public:
    Surface(Robot* robot);
    void draw(unsigned int frameIndex) override;
    void createRandomCubes();
    void despawnNextTrashCube();
    void layDownTrashCube();
    void pickUpOrLayDown();

};

#endif //WALL_E_SURFACE_H
