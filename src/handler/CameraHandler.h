#ifndef WALL_E_CAMERAHANDLER_H
#define WALL_E_CAMERAHANDLER_H

#include "../model/Handler.h"
#include "../api/vertex.h"

class CameraHandler: Handler {
private:
    VERTEX cameraPos;
    VERTEX lookAt;
    VERTEX up;

public:
    CameraHandler();
    void executeStep(unsigned int frameIndex) override;

    void setRoboterPerspective();
    void setBirdPerspective();
};


#endif //WALL_E_CAMERAHANDLER_H
