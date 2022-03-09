#ifndef WALL_E_SKY_H
#define WALL_E_SKY_H

#include "../../model/Scene.h"

/**
 * Includes following scenes:
 * - Sun
 */
class Sky: public Scene {
public:
    void draw(unsigned int frameIndex) const override;
};

#endif //WALL_E_SKY_H
