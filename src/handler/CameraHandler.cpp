#include "CameraHandler.h"
#include "../vendor/glut.h"
#include "../utilities/SceneGraph.h"

CameraHandler::CameraHandler() {
    // default
    setRoboterPerspective();
    lookAt = VERTEX{.15, 0, 0};
}

void CameraHandler::executeStep(const unsigned int frameIndex) {
    gluLookAt(cameraPos.x, cameraPos.y, cameraPos.z, lookAt.x, lookAt.y, lookAt.z, 0, 1, 0);
}

void CameraHandler::setRoboterPerspective() {
    cameraPos.x = robot.getPosition().x;
    cameraPos.y = robot.getPosition().y;
    cameraPos.z = robot.getPosition().z;
}

void CameraHandler::setBirdPerspective() {
    cameraPos.x = 0;
    cameraPos.y = 3;
    cameraPos.z = 0;
}

void CameraHandler::setPosition() {
    cameraPos.x = robot.getPosition().x;
    cameraPos.y = robot.getPosition().y;
    cameraPos.z = robot.getPosition().z;
}

VERTEX CameraHandler::getLookAt() {
    return lookAt;
}

