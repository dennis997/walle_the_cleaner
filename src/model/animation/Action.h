#ifndef WALL_E_ACTION_H
#define WALL_E_ACTION_H

#include "../../api/animation.h"

class Action {
public:
    virtual ~Action() = default;

    /**
     * Executes the transformation
     */
    virtual void execute() const = 0;

    /**
     * Updates transformation vertices
     *
     * @param animationNormal number between 0 and 1
     */
    virtual void update(float animationNormal) = 0;
};


#endif //WALL_E_ACTION_H
