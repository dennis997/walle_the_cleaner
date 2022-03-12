#ifndef WALL_E_WHEEL_H
#define WALL_E_WHEEL_H

#include "../../model/Scene.h"
#include <glm/glm.hpp>

#include "../../vendor/Model.h"

enum class WheelSide {
    LEFT, RIGHT
};

class Wheel: public Scene {
private:
    glm::vec3 position;
    WheelSide orientation;

    unsigned int wheelImgId;

    Model model;

    float size;

    void calculate(float roboterSize);
    void loadImage();

public:
    Wheel(WheelSide orientation);

    void draw(unsigned int frameIndex) const override;
};


#endif //WALL_E_WHEEL_H
