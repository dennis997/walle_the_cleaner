#include "Robot.h"
#include "math.h"
#include "../../vendor/glut.h"

Robot::Robot() {
    Parameter* parameter = Parameter::getInstance();

    position = parameter->getStartPosition();
    movementSpeed = parameter->getMovementSpeed();
    currentOrientation = parameter->getStartOrientation();
    angleSpeed = parameter->getMovementAngle();
    yAngle = parameter->getYAngle();

    carryCube = false;
    lightOn = false;
}

void Robot::draw(const unsigned int frameIndex) {
    glPopMatrix();
    {
        glColor3f(1, 1, 1);
        glTranslatef(position.x, position.y, position.z);
        glRotatef(45, 0, 1, 0);        // 45 degrees because std orientation = half a quadrant with look to 0,0,0
        Scene::draw(frameIndex);
    }
    glPopMatrix();
}

void Robot::moveForward() {
    if (!restrictMovement() || !movedForward) {
        prevPos = position;
        position += currentOrientation * movementSpeed;
        movedForward = true;
    }
    else
        position = prevPos;
}

void Robot::moveBack() {
    if (!restrictMovement() || movedForward) {
        prevPos = position;
        position -= currentOrientation * movementSpeed;
        movedForward = false;
    }
    else
        position = prevPos;
}

void Robot::moveLeft() {
    yAngle += angleSpeed;
    calcViewPoint(yAngle);
    //movedForward = !movedForward;
}

void Robot::moveRight() {
    yAngle -= angleSpeed;
    calcViewPoint(yAngle);
    //movedForward = !movedForward;
}

const glm::vec3 &Robot::getCurrentOrientation() const {
    return currentOrientation;
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

const glm::vec3 &Robot::getPosition() const {
    return position;
}


bool Robot::hasCube() const {
    return carryCube;
}

void Robot::setHasCube(bool hasCube) {
    this->carryCube = hasCube;
}
