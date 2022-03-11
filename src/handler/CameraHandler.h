#ifndef WALL_E_CAMERAHANDLER_H
#define WALL_E_CAMERAHANDLER_H

#include "../model/Handler.h"
#include "../api/vertex.h"
#include "glm/vec3.hpp"

struct LookAt {
    glm::vec3 position;
    glm::vec3 center;
    glm::vec3 up;
};

class CameraHandler: Handler {
private:
    LookAt lookAt;

public:
    CameraHandler();
    void executeStep(unsigned int frameIndex) override;

    void setEgoPerspective();
    void setBirdPerspective();
};


#endif //WALL_E_CAMERAHANDLER_H
