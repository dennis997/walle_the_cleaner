#include "Callback.h"

#include "../../vendor/glut.h"


Callback::Callback(CallbackFunction& callback): isExecuted(false), callback(callback) {}

void Callback::execute() const {}

void Callback::update(float animationNormal) {
    if (!isExecuted) {
        callback.callback();
        isExecuted = true;
    }
}
