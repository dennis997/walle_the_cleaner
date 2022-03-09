#ifndef WALL_E_KEYINPUT_H
#define WALL_E_KEYINPUT_H

#include "../utilities/HandlerManager.h"

void keyInputListener(unsigned char key, int x, int y) {

    switch(key) {
        case 'w':
            break;

        case 'a':
            break;

        case 's':
            break;

        case 'd':
            break;

        case 'b':
            cameraHandler.setBirdPerspective();
            break;

        case 'r':
            cameraHandler.setRoboterPerspective();
            break;
    }
}

#endif //WALL_E_KEYINPUT_H
