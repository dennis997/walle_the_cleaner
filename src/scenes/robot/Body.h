#ifndef WALL_E_BODY_H
#define WALL_E_BODY_H

#include "../../model/Scene.h"
#include "../../vendor/glut.h"
#include "../../vendor/Model.h"
#include <GL/freeglut.h>

class Body: public Scene {
private:
    unsigned int imageId;
    void loadImage();

    Model model;

public:
    Body();

    void draw(unsigned int frameIndex) override;
};

#endif //WALL_E_BODY_H
