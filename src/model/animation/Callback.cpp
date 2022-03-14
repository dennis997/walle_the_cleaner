#include "Callback.h"

#include "../../vendor/glut.h"


Callback::Callback(CallbackFunction& callback): isExecuted(false), isReversed(false), callback(callback) {}

void Callback::execute() const {}

void Callback::update(float animationNormal) {
    if (!isReversed && animationNormal < 0.f) {
        isExecuted = false;
        isReversed = true;
    }else if(!isExecuted && animationNormal > 0.f) {
        isExecuted = true;
        isReversed = false;
    }

    if (!isExecuted) {
        callback.callback();
        isExecuted = true;
    }
}
