#ifndef WALL_E_LOWER_ARM_H
#define WALL_E_LOWER_ARM_H

#include "../../../model/Scene.h"
#include "glm/vec3.hpp"
#include "../../../vendor/Model.h"
#include "../../../api/orientation.h"

class LowerArm: public Scene {
private:
    float armLength;

    glm::vec3 position;

    unsigned int imageId;
    Model model;

    void loadImage();
    void calculate();

public:
    float getArmLength() const;

public:
    LowerArm();

    void draw(unsigned int frameIndex) const override;
};


#endif
