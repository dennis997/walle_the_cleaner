#ifndef WALL_E_WHEEL_H
#define WALL_E_WHEEL_H

#include "../../model/Scene.h"
#include <glm/glm.hpp>


enum class WheelSide {
    LEFT, RIGHT
};

class Wheel: public Scene {
private:
    glm::vec3 position;
    WheelSide orientation;

    float size;

    void calculate(float roboterSize);

public:
    Wheel(WheelSide orientation);

    void draw(unsigned int frameIndex) const override;
};


#endif //WALL_E_WHEEL_H
