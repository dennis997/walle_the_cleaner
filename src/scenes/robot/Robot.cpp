#include "Robot.h"

Robot::Robot() {
    Parameter* parameter = Parameter::getInstance();

    position = parameter->getStartPosition();
    currentOrientation = parameter->getStartOrientation();
}

void Robot::draw(const unsigned int frameIndex) const {
    Scene::draw(frameIndex);
}

void Robot::turnUpwards() {

}
