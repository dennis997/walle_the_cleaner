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
private:

public:
    void draw(unsigned int frameIndex) override;
    void calculate() const;
    void drawSky() const;
};

#endif //WALL_E_SKY_H
