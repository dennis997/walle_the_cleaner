#ifndef WALL_E_ROBOTHANDLER_H
#define WALL_E_ROBOTHANDLER_H

#include "../utilities/SceneGraph.h"

void moveUp() {
    robot.turnUpwards();
    // we need a callback here to move up in the next step
    // TODO
}

#endif //WALL_E_ROBOTHANDLER_H
