#ifndef WALL_E_TRANSLATE_H
#define WALL_E_TRANSLATE_H

#include "Action.h"
#include <glm/glm.hpp>

class Translate: public Action {
private:
    const glm::vec3 direction;
    glm::vec3 currentDirection;

public:
    Translate(const glm::vec3 &direction);

    void execute() const override;
    void update(float animationNormal) override;
    void notify(const animation::State state) override;
};


#endif //WALL_E_TRANSLATE_H
