#ifndef WALL_E_HANDLERMANAGER_H
#define WALL_E_HANDLERMANAGER_H

#include "../model/Handler.h"
#include "../handler/CameraHandler.h"
#include "../handler/RoboterHandler.h"


CameraHandler cameraHandler;
RoboterHandler roboterHandler;

void invokeHandlers(const unsigned int frameIndex) {
    cameraHandler.executeStep(frameIndex);
    roboterHandler.executeStep(frameIndex);
}

#endif //WALL_E_HANDLERMANAGER_H
