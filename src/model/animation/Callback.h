#ifndef WALL_E_CALLBACK_H
#define WALL_E_CALLBACK_H

#include "Action.h"
#include <glm/glm.hpp>
#include "../../scenes/robot/Carriage.h"

struct CallbackFunction {
    std::function<void()> callback;
};

class Callback: public Action {
private:
    bool isExecuted;
    CallbackFunction callback;

public:
    Callback(CallbackFunction& callback);

    void execute() const override;
    void update(float animationNormal) override;
};


#endif //WALL_E_CALLBACK_H
