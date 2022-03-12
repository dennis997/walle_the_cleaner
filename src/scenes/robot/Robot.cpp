#include "Robot.h"
#include "iostream"
#include "math.h"
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

    std::cout << "X: " << currentOrientation.x << "| Z: " << currentOrientation.z << std::endl;
}

void Robot::moveBack() {
    Parameter* parameter = Parameter::getInstance();

    position += (position - currentOrientation) * parameter->getMovementSpeed();
    currentOrientation += (position - currentOrientation) * parameter->getMovementSpeed();

    std::cout << "X: " << currentOrientation.x << "| Z: " << currentOrientation.z << std::endl;
}

void Robot::moveLeft() {
    std::cout << "yAngle: " << yAngle << "°" << std::endl;
    Parameter* parameter = Parameter::getInstance();
    yAngle -= 5;
    if (yAngle > 0)
        yAngle = 355;
    calcViewPoint(yAngle);
    std::cout << "yAngle: " << yAngle << "°" << std::endl;

    std::cout << "X: " << currentOrientation.x << "| Z: " << currentOrientation.z << std::endl;
}

void Robot::moveRight() {
    std::cout << "yAngle: " << yAngle << "°" << std::endl;
    Parameter* parameter = Parameter::getInstance();
    yAngle += 5;
    if (yAngle > 355)
        yAngle = 0;
    calcViewPoint(yAngle);
    std::cout << "yAngle: " << yAngle << "°" << std::endl;

    std::cout << "X: " << currentOrientation.x << "| Z: " << currentOrientation.z << std::endl;
}

const glm::vec3 &Robot::getCurrentOrientation() const {
    return currentOrientation;
}

void Robot::calcViewPoint(int degree) {
    float currentDegree = (0.0175 * (degree - 45));

    currentOrientation.x = cos(currentDegree) + sin(currentDegree);
    currentOrientation.z = cos(currentDegree) - sin(currentDegree);
}
