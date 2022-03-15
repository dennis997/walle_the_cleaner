#include "Robot.h"
#include "math.h"
#include "../../vendor/glut.h"

const float DEFAULT_ANGLE = 45.f;

Robot::Robot() {
    Parameter* parameter = Parameter::getInstance();

    position = parameter->getStartPosition();
    movementSpeed = parameter->getMovementSpeed();
    currentOrientation = parameter->getStartOrientation();
    angleSpeed = parameter->getMovementAngle();
    yAngle = parameter->getYAngle();
    idleDuration = parameter->getIdleDuration();

    carryCube = false;
    lightOn = false;
    stickyAngle = DEFAULT_ANGLE;
}

void Robot::draw(const unsigned int frameIndex) {
    handleIdle(frameIndex);

    glPopMatrix();
    {
        glColor3f(1, 1, 1);
        glTranslatef(position.x, position.y, position.z);
        glRotatef(getAngle(), 0, 1, 0);
        Scene::draw(frameIndex);
    }
    glPopMatrix();
}

void Robot::moveForward() {
    resetIdleTimer();

    if (!restrictMovement() || !movedForward) {
        prevPos = position;
        position += currentOrientation * movementSpeed;
        movedForward = true;
    }
    else
        position = prevPos;
}

void Robot::moveBack() {
    resetIdleTimer();

    if (!restrictMovement() || movedForward) {
        prevPos = position;
        position -= currentOrientation * movementSpeed;
        movedForward = false;
    }
    else
        position = prevPos;
}

void Robot::moveLeft() {
    resetIdleTimer();


    yAngle += angleSpeed;
    calcViewPoint(yAngle);
    //movedForward = !movedForward;
}

void Robot::moveRight() {
    resetIdleTimer();

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

void Robot::toggleSticky() {
    isSticky = !isSticky;

    if (isSticky) {
        stickyAngle = yAngle + DEFAULT_ANGLE;
        stickyOrientation = currentOrientation;
    }
}

/**
 * 45 degrees because std orientation = half a quadrant with look to 0,0,0
 * @return
 */
float Robot::getAngle() {
    if (isSticky) {
        return stickyAngle;
    }

    return DEFAULT_ANGLE + yAngle;
}

int idleCounter = 0;
void Robot::handleIdle(const unsigned int frameIndex) {
    if (lastMovementFrameIndex == -1 || carryCube) {
        lastMovementFrameIndex = frameIndex;
        return;
    }

    if (frameIndex - lastMovementFrameIndex > idleDuration) {
        startIdleAnimation(frameIndex);
        lastMovementFrameIndex = -1.f;
    }
}

void Robot::resetIdleTimer() {
    lastMovementFrameIndex = -1.f;
}

int Robot::getYAngle() const {
    return yAngle;
}

const glm::vec3 &Robot::getOrientation() const {
    return isSticky ? stickyOrientation : currentOrientation;
}
