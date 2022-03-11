#include "Sky.h"

void Sky::draw(const unsigned int frameIndex) const {
    drawSky();
    Scene::draw(frameIndex);
}

void Sky::calculate() const {

}

void Sky::drawSky() const {
    glClearColor(0.0, 0.0, 0.4, 1.0);
}