#ifndef WALL_E_LOWER_ARM_H
#define WALL_E_LOWER_ARM_H

#include "../../../model/Scene.h"
#include "glm/vec3.hpp"
#include "../../../vendor/Model.h"
#include "../../../api/orientation.h"

class LowerArm: public Scene {
private:
    float size;
    Side orientation;

    glm::vec3 position;

    unsigned int imageId;
    Model model;

    void loadImage();
    void calculate();

public:
    LowerArm(Side armSide);

    void draw(unsigned int frameIndex) const override;
};


#endif
