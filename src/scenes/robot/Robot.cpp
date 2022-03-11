#include "Robot.h"


Robot::Robot() {
    Parameter* parameter = Parameter::getInstance();

    position = parameter->getStartPosition();
    currentOrientation = parameter->getStartOrientation();
}

void Robot::draw(const unsigned int frameIndex) const {
    Scene::draw(frameIndex);
}

VERTEX Robot::getPosition() const {
    return position;
}

void Robot::turnUpwards() {

}

void Robot::moveForward() {
    glm::vec3 currentPosition {position.x, position.y, position.z};
    glm::vec3 cameraViewPoint {cameraHandler.getLookAt().x, cameraHandler.getLookAt().y, cameraHandler.getLookAt().z};
    glm::vec3 newPosition = currentPosition - ((currentPosition - cameraViewPoint) * Parameter::getMovementSpeed());

    position = VERTEX(newPosition.x, newPosition.y, newPosition.z);

    cameraHandler.setPosition();
}

void Robot::moveBack() {

}

void Robot::moveLeft() {

}

void Robot::moveRight() {

}

