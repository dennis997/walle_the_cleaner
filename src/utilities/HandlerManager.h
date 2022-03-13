#ifndef WALL_E_HANDLERMANAGER_H
#define WALL_E_HANDLERMANAGER_H

#include "../model/Handler.h"
#include "../handler/CameraHandler.h"

class HandlerManager {
private:
    CameraHandler* cameraHandler{};

    void init() {
        cameraHandler = new CameraHandler;
    }

public:
    HandlerManager() {
        init();
    }

    void invokeHandlers(const unsigned int frameIndex) {
        cameraHandler->executeStep(frameIndex);
    }

    CameraHandler *getCameraHandler() const {
        return cameraHandler;
    }
};



#endif //WALL_E_HANDLERMANAGER_H
