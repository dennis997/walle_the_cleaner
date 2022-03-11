#ifndef WALL_E_KEYINPUT_H
#define WALL_E_KEYINPUT_H

#include "../utilities/HandlerManager.h"

void keyInputListener(unsigned char key, int x, int y, HandlerManager *handlerManager) {
    CameraHandler* cameraHandler = handlerManager->getCameraHandler();

    switch(key) {
        case 'w':
            robot.moveForward();
            cameraHandler->setEgoPerspective();
            break;

        case 'a':
            robot.moveLeft();
            break;

        case 's':
            robot.moveBack();
            break;

        case 'd':
            robot.moveRight();
            break;

        case 'b':
            cameraHandler->setBirdPerspective();
            break;

        case 'r':
            cameraHandler->setEgoPerspective();
            break;
    }
}


#endif //WALL_E_KEYINPUT_H
