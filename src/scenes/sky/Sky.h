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
    void draw(unsigned int frameIndex) const override;
    void calculate() const;
    void drawSky() const;

private:
    struct SKYBOXPLATE {
        VERTEX v_1;
        VERTEX v_2;
        VERTEX v_3;
        VERTEX v_4;
    };
    GLuint skyBoxImage;
};

#endif //WALL_E_SKY_H
