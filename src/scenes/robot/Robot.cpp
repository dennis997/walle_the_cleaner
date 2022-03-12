#include "Robot.h"
#include "math.h"
#include <iostream>
#include "../../vendor/glut.h"

Robot::Robot() {
    Parameter* parameter = Parameter::getInstance();

    position = parameter->getStartPosition();
    currentOrientation = parameter->getStartOrientation();
    yAngle = parameter->getYAngle();
}

void Robot::draw(const unsigned int frameIndex) const {
    glPopMatrix();
    {
        glTranslatef(position.x, position.y, position.z);
        glRotatef(yAngle + 45, 0, 1, 0);
        Scene::draw(frameIndex);
    }
    glPopMatrix();
}

const glm::vec3 &Robot::getPosition() const {
    return position;
}

void Robot::moveForward() {
    std::cout << "X: " << position.x << "| Z: " << position.z << std::endl;
    Parameter* parameter = Parameter::getInstance();
    if (!restrictMovement() || !movedForward) {
        position += currentOrientation * parameter->getMovementSpeed();
        movedForward = true;
    }
}

void Robot::moveBack() {
    std::cout << "X: " << position.x << "| Z: " << position.z << std::endl;
    Parameter* parameter = Parameter::getInstance();
    if (!restrictMovement() || movedForward) {
        position -= currentOrientation * parameter->getMovementSpeed();
        movedForward = false;
    }
}

void Robot::moveLeft() {
    Parameter* parameter = Parameter::getInstance();
    yAngle += parameter->getMovementAngle();

    calcViewPoint(yAngle);
}

void Robot::moveRight() {
    Parameter* parameter = Parameter::getInstance();
    yAngle -= parameter->getMovementAngle();

    calcViewPoint(yAngle);
}

const glm::vec3 &Robot::getCurrentOrientation() const {
    return currentOrientation;
}

void Robot::calcViewPoint(int degree) {
    float currentDegree = 0.0175f * degree;

    currentOrientation.x = cos(currentDegree) + sin(currentDegree);
    currentOrientation.z = cos(currentDegree) - sin(currentDegree);
}

bool Robot::restrictMovement() {
    Parameter* parameter = Parameter::getInstance();
    float offsetBoarder = 0.8f;

    if (position.x > parameter->getFieldSize() - offsetBoarder ||
        position.z > parameter->getFieldSize() -offsetBoarder ||
        position.x < 0 + offsetBoarder ||
        position.z < 0 + offsetBoarder)
        return true;
    return false;
}

