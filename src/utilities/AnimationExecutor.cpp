#include "AnimationExecutor.h"
#include "Parameters.h"

#include "../model/animation/Action.h"

float frameSleepDuration;

AnimationExecutor::AnimationExecutor(): startFrameIndex{0}, maxDelay{0} {
    // average frame calculation time offset -> bit hacky
    float timeOffset = 7.f;

    Parameter *parameters = Parameter::getInstance();
    frameSleepDuration = parameters->getWaitDuration() + timeOffset;
}

void AnimationExecutor::start(unsigned int frameIndex) {
    startFrameIndex = frameIndex;
    // animate reverse if the animation is at the end
    for (auto &step: steps) {
        step->state = step->state == State::START ? State::RUNNING : State::RUNNING_REV;
        step->action->notify(step->state);
    }
}

void AnimationExecutor::execute(unsigned int frameIndex) {
    float timePassed = (frameIndex - startFrameIndex) * frameSleepDuration;


    for (const auto &step : steps) {
        if (step->state == State::START || step->state == State::END) {
            continue;
        }

        // subtract delay from max delay of all steps when the animation is reversed
        float animationDelay = step->state == State::RUNNING ? step->delay : maxDelay -step->delay;

        // if delay is passed calculate update
        if (animationDelay > timePassed) {
            continue;
        }

        float relativeTime = (timePassed - animationDelay) / step->duration;
        // animation is over if time passed is greater than duration
        if (relativeTime <= 1.f) {
            float _relativeTime = relativeTime;

            if (step->state == State::RUNNING_REV) {
                _relativeTime = 1.f - relativeTime;
            }

            step->action->update(_relativeTime);
        } else {
            step->state = step->state == State::RUNNING_REV ? State::START : State::END;
            step->action->notify(step->state);
        }
    }
}


void AnimationExecutor::addAnimationStep(Step *step) {
    steps.push_back(step);

    if (step->delay > maxDelay) {
        maxDelay = step->delay;
    }
}

void AnimationExecutor::animate(const unsigned int frameIndex) {
    execute(frameIndex);

    for (const auto &step: steps) {
        step->action->execute();
    }
}
