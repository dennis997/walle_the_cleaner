#include "Translate.h"

#include "../../vendor/glut.h"

Translate::Translate(const glm::vec3 &direction): direction(direction) {
    currentDirection = glm::vec3(0.f, 0.f, 0.f);
}

void Translate::execute() const {
    glTranslatef(currentDirection.x, currentDirection.y, currentDirection.z);
}

void Translate::update(float animationNormal) {
    currentDirection = direction * animationNormal;
}