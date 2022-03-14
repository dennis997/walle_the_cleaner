#include "Visibility.h"

#include "../../vendor/glut.h"

Visibility::Visibility(): currentAlpha(1.f) {

}


void Visibility::execute() const {
    glColor4f(currentAlpha, currentAlpha, currentAlpha, currentAlpha);
}

void Visibility::update(float animationNormal) {
    currentAlpha = 1.f - animationNormal;
}
