#ifndef WALL_E_SURFACE_H
#define WALL_E_SURFACE_H

#include "../../model/Scene.h"

/**
 * Includes following scenes:
 * - Ground
 * - TrashCube
 * - ....
 */
class Surface: public Scene {
public:
    void draw() const override;
};

#endif //WALL_E_SURFACE_H
