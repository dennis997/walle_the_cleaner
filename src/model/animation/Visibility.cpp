#include "Visibility.h"

#include "../../vendor/glut.h"

Visibility::Visibility(): currentAlpha(0.f) {

}

void Visibility::execute() const {
    glColor4f(currentAlpha, currentAlpha, currentAlpha, currentAlpha);
}

void Visibility::update(float animationNormal) {
    currentAlpha = animationNormal;
}
