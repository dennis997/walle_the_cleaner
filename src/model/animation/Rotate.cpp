#include "Rotate.h"

#include "../../vendor/glut.h"


Rotate::Rotate(const float angle, const glm::vec3 &axis): angle(angle), currentAngle(0.f),axis(axis) {

}


void Rotate::execute() const {
    glRotatef(currentAngle, axis.x, axis.y, axis.z);
}

void Rotate::update(float animationNormal) {
    currentAngle = angle * animationNormal;
}
