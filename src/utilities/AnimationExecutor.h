#ifndef WALL_E_ANIMATIONEXECUTOR_H
#define WALL_E_ANIMATIONEXECUTOR_H

#include "../api/animation.h"
#include <vector>

using namespace animation;

class AnimationExecutor {
private:
    std::vector<Step*> steps;

    unsigned int startFrameIndex;
    void execute(unsigned int frameIndex);
    float maxDelay;

public:
    AnimationExecutor();

    void addAnimationStep(Step *step);
    void start(unsigned int frameIndex);
    void animate(unsigned int frameIndex);
};


#endif //WALL_E_ANIMATIONEXECUTOR_H
