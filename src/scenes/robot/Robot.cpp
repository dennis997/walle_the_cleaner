#include "Robot.h"

#include "../../vendor/glut.h"

Robot::Robot() {
    Parameter* parameter = Parameter::getInstance();

    position = parameter->getStartPosition();
    currentOrientation = parameter->getStartOrientation();
}

void Robot::draw(const unsigned int frameIndex) const {
    glPopMatrix();
    {
        glTranslatef(position.x, position.y, position.z);
        Scene::draw(frameIndex);
    }
    glPopMatrix();
}

const glm::vec3 &Robot::getPosition() const {
    return position;
}

void Robot::moveForward() {
    Parameter* parameter = Parameter::getInstance();

    position -= (position - currentOrientation) * parameter->getMovementSpeed();
    currentOrientation -= (position - currentOrientation) * parameter->getMovementSpeed();
}

void Robot::moveBack() {
    
}

void Robot::moveLeft() {

}

void Robot::moveRight() {

}

const glm::vec3 &Robot::getCurrentOrientation() const {
    return currentOrientation;
}
