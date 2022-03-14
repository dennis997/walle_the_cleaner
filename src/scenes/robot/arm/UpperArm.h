#ifndef WALL_E_ARM_H
#define WALL_E_ARM_H

#include "../../../model/Scene.h"
#include "glm/vec3.hpp"
#include "../../../vendor/Model.h"
#include "../../../api/api.h"
#include "../../../utilities/AnimationExecutor.h"

class UpperArm: public Scene {
private:
    Side orientation;
    glm::vec3 position;
    unsigned int imageId;
    Model model;

    void loadImage();
    void calculate();
    void initAnimation();

public:
    UpperArm(Side armSide);

    void draw(unsigned int frameIndex) override;

    Side getOrientation() const;
};


#endif
