#ifndef WALL_E_KEYINPUT_H
#define WALL_E_KEYINPUT_H

#include "../handler/robotHandler.h"

void keyInputListener(unsigned char key, int x, int y) {

    switch(key) {
        case 'w':
            moveUp();
            break;

        case 'a':
            break;

        case 's':
            break;

        case 'd':
            break;
    }
}

#endif //WALL_E_KEYINPUT_H
