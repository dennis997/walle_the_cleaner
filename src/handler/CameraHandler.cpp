#include "CameraHandler.h"
#include "../vendor/glut.h"
#include "../utilities/SceneGraph.h"

CameraHandler::CameraHandler() {
    // default
    setEgoPerspective();
}

void CameraHandler::executeStep(const unsigned int frameIndex) {
    gluLookAt(lookAt.position.x, lookAt.position.y, lookAt.position.z,
              lookAt.center.x, lookAt.center.y, lookAt.center.z,
              lookAt.up.x, lookAt.up.y, lookAt.up.z
    );
}

void CameraHandler::setEgoPerspective() {
    lookAt.position = robot.getPosition();
    lookAt.center = robot.getCurrentOrientation();

    lookAt.position.y = .5; // TODO set robot head y value when its present
}

void CameraHandler::setBirdPerspective() {
    lookAt.position.x = 0;
    lookAt.position.y = 3;
    lookAt.position.z = 0;
}

