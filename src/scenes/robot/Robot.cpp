#include "Robot.h"
#include "math.h"
#include <iostream>
#include "../../vendor/glut.h"

Robot::Robot() {
    Parameter* parameter = Parameter::getInstance();

    position = parameter->getStartPosition();
    currentOrientation = parameter->getStartOrientation();
    yAngle = parameter->getYAngle();
    lightOn = false;

}

void Robot::draw(const unsigned int frameIndex) const {
    glPopMatrix();
    {
        glTranslatef(position.x, position.y, position.z);
        glRotatef(45, 0, 1, 0);        // 45 degrees because std orientation = half a quadrant with look to 0,0,0
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
        prevPos = position;
        position += currentOrientation * parameter->getMovementSpeed();
        movedForward = true;
    }
    else
        position = prevPos;
}

void Robot::moveBack() {
    std::cout << "X: " << position.x << "| Z: " << position.z << std::endl;
    Parameter* parameter = Parameter::getInstance();
    if (!restrictMovement() || movedForward) {
        prevPos = position;
        position -= currentOrientation * parameter->getMovementSpeed();
        movedForward = false;
    }
    else
        position = prevPos;
}

void Robot::moveLeft() {
    Parameter* parameter = Parameter::getInstance();
    yAngle += parameter->getMovementAngle();
    calcViewPoint(yAngle);
    //movedForward = !movedForward;
}

void Robot::moveRight() {
    Parameter* parameter = Parameter::getInstance();
    yAngle -= parameter->getMovementAngle();
    calcViewPoint(yAngle);
    //movedForward = !movedForward;
}

const glm::vec3 &Robot::getCurrentOrientation() const {
    return currentOrientation;
}

const int Robot::getYAngle() const {
    return yAngle;
}

void Robot::calcViewPoint(int degree) {
    Parameter* parameter = Parameter::getInstance();
    float currentDegree = parameter->getRadiantApprox() * degree;

    currentOrientation.x = cos(currentDegree) + sin(currentDegree);
    currentOrientation.z = cos(currentDegree) - sin(currentDegree);
}

bool Robot::restrictMovement() {
    Parameter* parameter = Parameter::getInstance();
    float offsetBoarder = 0.5f;

    if (position.x > parameter->getFieldSize() - offsetBoarder ||
        position.z > parameter->getFieldSize() - offsetBoarder ||
        position.x < 0 + offsetBoarder ||
        position.z < 0 + offsetBoarder)
        return true;
    return false;
}

void Robot::toggleLight(Perspective currentPerspective) {
    if (lightOn) {
            glDisable(GL_LIGHT1);
            glDisable(GL_LIGHT2);
        lightOn = false;
    }
    else {
        if (currentPerspective == Perspective::EGO)
            glEnable(GL_LIGHT1);
        if (currentPerspective == Perspective::THIRDPERSON)
            glEnable(GL_LIGHT2);
        lightOn = true;
    }

}

const bool Robot::getLightStatus() const {
    return lightOn;
}

