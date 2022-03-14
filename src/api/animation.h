#ifndef WALL_E_ANIMATION_H
#define WALL_E_ANIMATION_H

#include <glm/glm.hpp>
#include "../vendor/glut.h"
#include "../model/animation/Action.h"

class Action;

namespace animation {
    enum class State {
        START, RUNNING, RUNNING_REV, END
    };

    struct Step {
        Action *action;

        State state;

        /**
         * in ms
         */
        float duration;

        /**
         * in ms
         */
        float delay;

        Step(Action *action, float duration) : action(action), duration(duration), delay(0.f), state(State::START) {}
        Step(Action *action, float duration, float delay) : action(action), duration(duration), delay(delay), state(State::START) {}
    };
}

#endif //WALL_E_ANIMATION_H
