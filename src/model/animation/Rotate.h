#ifndef WALL_E_ROTATE_H
#define WALL_E_ROTATE_H

#include "Action.h"
#include <glm/glm.hpp>

class Rotate: public Action {
private:
    const float angle;
    float currentAngle;
    glm::vec3 axis;


public:
    Rotate(const float angle, const glm::vec3 &axis);

    void execute() const override;
    void update(float animationNormal) override;
    void notify(const animation::State state) override;
};


#endif //WALL_E_ROTATE_H
