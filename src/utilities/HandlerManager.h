#ifndef WALL_E_HANDLERMANAGER_H
#define WALL_E_HANDLERMANAGER_H

#include "../model/Handler.h"
#include "../handler/CameraHandler.h"
#include "../handler/RoboterHandler.h"

class HandlerManager {
private:
    CameraHandler* cameraHandler{};
    RoboterHandler* roboterHandler{};

    void init() {
        cameraHandler = new CameraHandler;
        roboterHandler = new RoboterHandler;
    }

public:
    HandlerManager() {
        init();
    }

    void invokeHandlers(const unsigned int frameIndex) {
        cameraHandler->executeStep(frameIndex);
        roboterHandler->executeStep(frameIndex);
    }

    CameraHandler *getCameraHandler() const {
        return cameraHandler;
    }

    RoboterHandler *getRoboterHandler() const {
        return roboterHandler;
    }
};



#endif //WALL_E_HANDLERMANAGER_H
