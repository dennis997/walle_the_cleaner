#ifndef WALL_E_ARM_H
#define WALL_E_ARM_H

#include "../../model/Scene.h"
#include "glm/vec3.hpp"
#include "../../vendor/Model.h"
#include "../../api/orientation.h"

class Arm: public Scene {
private:
    float size;
    Side orientation;

    glm::vec3 position;

    unsigned int eyeImageId;
    Model model;

    void loadImage();
    void calculate();

public:
    Arm(Side armSide);

    void draw(unsigned int frameIndex) const override;
};


#endif
