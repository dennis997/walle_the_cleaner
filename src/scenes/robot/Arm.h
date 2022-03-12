#ifndef WALL_E_ARM_H
#define WALL_E_ARM_H

#include "../../model/Scene.h"
#include "glm/vec3.hpp"

enum class ArmSide {
    LEFT, RIGHT
};

class Arm: public Scene {
private:
    glm::vec3 position;
    ArmSide orientation;

    float width;
    float length;

    void calculate(float roboterSize);

public:
    Arm(ArmSide armSide);

    void draw(unsigned int frameIndex) const override;
};


#endif //WALL_E_ARM_H
