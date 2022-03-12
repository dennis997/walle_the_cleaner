#ifndef WALL_E_BODY_H
#define WALL_E_BODY_H

#include "../../model/Scene.h"
#include "../../vendor/glut.h"


class Body: public Scene {
private:
    float size;

    unsigned int bodyImageId;
    void loadImage();

public:
    Body();

    void draw(unsigned int frameIndex) const override;
};

#endif //WALL_E_BODY_H
