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
    currentPerspective = Perspective::EGO;

    lookAt.up.x = 0;
    lookAt.up.y = 1;
    lookAt.up.z = 0;

    update();
}

void CameraHandler::setBirdPerspective() {
    currentPerspective = Perspective::BIRD;

    Parameter* parameters = Parameter::getInstance();
    int fieldSize = parameters->getFieldSize();

    lookAt.position.x = fieldSize / 2;
    lookAt.position.y = 13;
    lookAt.position.z = fieldSize / 2;

    lookAt.center.x = fieldSize / 2;
    lookAt.center.y = 0;
    lookAt.center.z = fieldSize / 2;

    lookAt.up.x = 1;
    lookAt.up.y = 0;
    lookAt.up.z = 0;
}

void CameraHandler::update() {
    if (currentPerspective == Perspective::EGO) {
        lookAt.position = robot.getPosition();
        lookAt.center = robot.getCurrentOrientation() + robot.getPosition();

        lookAt.position.y = .5; // TODO set robot head y value when its present
        lookAt.center.y = .5; // TODO set robot head y value when its present
    }
}
