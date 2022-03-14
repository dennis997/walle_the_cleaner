#ifndef WALL_E_LOWER_ARM_H
#define WALL_E_LOWER_ARM_H

#include "../../../model/Scene.h"
#include "glm/vec3.hpp"
#include "../../../vendor/Model.h"
#include "../../../api/api.h"

class LowerArm: public Scene {
private:
    float armLength;
    glm::vec3 position;
    unsigned int imageId;
    Model model;
    const Side orientation;

    void loadImage();
    void calculate();
    void initAnimation();

public:
    LowerArm(Side side);
    float getArmLength() const;

public:
    LowerArm();

    void draw(unsigned int frameIndex) override;
};


#endif
