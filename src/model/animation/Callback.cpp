#include "Callback.h"

Callback::Callback(CallbackFunction& callback): isExecuted(false), callback(callback) {}

void Callback::execute() const {}

void Callback::update(float animationNormal) {
    if (!isExecuted) {
        callback.callback();
        isExecuted = true;
    }
}

void Callback::notify(const animation::State state) {
    if (state == animation::State::START || state == animation::State::END) {
        isExecuted = false;
    }
}
