#ifndef WALL_E_SKY_H
#define WALL_E_SKY_H

#include <GL/gl.h>
#include "../../model/Scene.h"
#include "Sun.h"

/**
 * Includes following scenes:
 * - Sun
 */
class Sky: public Scene {
public:
    void draw(unsigned int frameIndex) override;
};

#endif //WALL_E_SKY_H
