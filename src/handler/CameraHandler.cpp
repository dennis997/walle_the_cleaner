#include "CameraHandler.h"
#include "../vendor/glut.h"
#include "../utilities/SceneGraph.h"
#include <math.h>
#include "iostream"

CameraHandler::CameraHandler() {
    // default
    setThirdPersonPerspective();
}

void CameraHandler::executeStep(const unsigned int frameIndex) {
    gluLookAt(lookAt.position.x, lookAt.position.y, lookAt.position.z,
              lookAt.center.x, lookAt.center.y, lookAt.center.z,
              lookAt.up.x, lookAt.up.y, lookAt.up.z
    );
}

void CameraHandler::setEgoPerspective() {
    currentPerspective = Perspective::EGO;
    glDisable(GL_LIGHT2);

    if (robot->getLightStatus())
        glEnable(GL_LIGHT1);

    lookAt.up.x = 0;
    lookAt.up.y = 1;
    lookAt.up.z = 0;

    update();
}

void CameraHandler::setBirdPerspective() {
    currentPerspective = Perspective::BIRD;
    glDisable(GL_LIGHT1);
    glDisable(GL_LIGHT2);

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

void CameraHandler::setThirdPersonPerspective() {
    currentPerspective = Perspective::THIRDPERSON;
    glDisable(GL_LIGHT1);
    if (robot->getLightStatus())
        glEnable(GL_LIGHT2);

    lookAt.up.x = 0;
    lookAt.up.y = 1;
    lookAt.up.z = 0;

    update();
}

void CameraHandler::update() {
    switch (currentPerspective) {
        case Perspective::EGO:
            lookAt.position = robot->getPosition();
            lookAt.center = robot->getCurrentOrientation() + robot->getPosition();

            lookAt.position.y = .5;
            lookAt.center.y = .5;
            break;

        case Perspective::THIRDPERSON:
            float offsetX = 1.7f * robot->getCurrentOrientation().x;
            float offsetZ = 1.7f * robot->getCurrentOrientation().z;

            lookAt.position.x = robot->getPosition().x - offsetX;
            lookAt.position.z = robot->getPosition().z - offsetZ;
            lookAt.center = robot->getCurrentOrientation() + robot->getPosition();

            lookAt.position.y = 1.25f;
            lookAt.center.y = .5;
            break;
    }
}

Perspective CameraHandler::getCurrentPerspective() {
    return currentPerspective;
}
