#ifndef WALL_E_KEYINPUT_H
#define WALL_E_KEYINPUT_H

#include "../utilities/HandlerManager.h"

void keyInputListener(unsigned char key, int x, int y, HandlerManager *handlerManager, const unsigned int frameIndex) {
    CameraHandler* cameraHandler = handlerManager->getCameraHandler();

    switch(key) {
        case 'w':
            robot->moveForward();
            cameraHandler->update();
            break;

        case 'a':
            robot->moveLeft();
            cameraHandler->update();
            break;

        case 's':
            robot->moveBack();
            cameraHandler->update();
            break;

        case 'd':
            robot->moveRight();
            cameraHandler->update();
            break;

        case 'b':
            cameraHandler->setBirdPerspective();
            break;

        case 'r':
            cameraHandler->setEgoPerspective();
            break;

        case 't':
            cameraHandler->setThirdPersonPerspective();
            break;

        case 'l':
            robot->toggleLight(cameraHandler->getCurrentPerspective());
            break;

        case 'g':
            robot->startGrabAnimation(frameIndex);
            break;

        case 'c':
            robot->toggleSticky();
            break;
    }
}

#endif //WALL_E_KEYINPUT_H
