#ifndef WALL_E_VISIBILITY_H
#define WALL_E_VISIBILITY_H

#include "Action.h"
#include <glm/glm.hpp>

class Visibility: public Action {
private:
    float currentAlpha;

public:
    Visibility();

    void execute() const override;
    void update(float animationNormal) override;
    void notify(const animation::State state) override;
};


#endif //WALL_E_VISIBILITY_H
