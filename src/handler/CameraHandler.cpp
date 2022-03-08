#include "CameraHandler.h"
#include "../vendor/glut.h"

CameraHandler::CameraHandler() {
    // default
    setBirdPerspective();
}

void CameraHandler::executeStep(const unsigned int frameIndex) {
    gluLookAt(cameraPos.x, cameraPos.y, cameraPos.z, 0, 0, 0, 0, 1, 0);
}

void CameraHandler::setRoboterPerspective() {
    //TODO get roboter position
    cameraPos.x = -.3;
    cameraPos.y = .1;
    cameraPos.z = .2;
}

void CameraHandler::setBirdPerspective() {
    cameraPos.x = .3;
    cameraPos.y = .5;
    cameraPos.z = 1;
}
