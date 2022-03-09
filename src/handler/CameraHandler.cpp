#include "CameraHandler.h"
#include "../vendor/glut.h"

CameraHandler::CameraHandler() {
    // default
    setRoboterPerspective();
}

void CameraHandler::executeStep(const unsigned int frameIndex) {
    gluLookAt(cameraPos.x, cameraPos.y, cameraPos.z, .15, 0, 0, 0, 1, 0);
}

void CameraHandler::setRoboterPerspective() {
    //TODO get roboter position
    cameraPos.x = .15;
    cameraPos.y = .05;
    cameraPos.z = 1;
}

void CameraHandler::setBirdPerspective() {
    cameraPos.x = 0;
    cameraPos.y = 3;
    cameraPos.z = 0;
}
