#ifndef WALL_E_WHEEL_H
#define WALL_E_WHEEL_H

#include "../../model/Scene.h"
#include "../../api/vertex.h"


enum class WheelOrientation {
    LEFT, RIGHT
};

class Wheel: public Scene {
private:
    VERTEX position;
    WheelOrientation orientation;

    float size;

    void calculate(float bodySize);

public:
    Wheel(WheelOrientation orientation, float bodySize);

    void draw(unsigned int frameIndex) const override;
};


#endif //WALL_E_WHEEL_H
