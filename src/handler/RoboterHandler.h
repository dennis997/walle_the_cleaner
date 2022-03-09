#ifndef WALL_E_ROBOTERHANDLER_H
#define WALL_E_ROBOTERHANDLER_H

#include "../utilities/Parameters.h"

#include "../model/Handler.h"

class RoboterHandler: Handler {
private:


public:
    RoboterHandler() = default;
    void executeStep(unsigned int frameIndex) override;
};


#endif //WALL_E_ROBOTERHANDLER_H
