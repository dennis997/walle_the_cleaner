#ifndef WALL_E_CAMERAHANDLER_H
#define WALL_E_CAMERAHANDLER_H

#include "../model/Handler.h"
#include "glm/vec3.hpp"

struct LookAt {
    glm::vec3 position;
    glm::vec3 center;
    glm::vec3 up;
};

enum class Perspective {
    EGO, BIRD, DEBUG
};

class CameraHandler: Handler {
private:
    LookAt lookAt;
    Perspective currentPerspective;

public:
    CameraHandler();
    void executeStep(unsigned int frameIndex) override;

    void update();

    void setEgoPerspective();
    void setBirdPerspective();
    void setDebugPerspective();
};


#endif //WALL_E_CAMERAHANDLER_H
