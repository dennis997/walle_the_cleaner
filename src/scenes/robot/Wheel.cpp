#include "Wheel.h"

#include "../../vendor/glut.h"

Wheel::Wheel(const WheelOrientation orientation, const float bodySize): orientation(orientation) {
    size = .2;

    calculate(bodySize);
}

void Wheel::draw(unsigned int frameIndex) const {
    glPushMatrix();
    {
        glColor3f(.44, .47, .49);
        glBegin(GL_TRIANGLES);
        {
            glVertex3f(position.x, -size * .1, size * -.5);
            glVertex3f(position.x, size * .2, size * -.5);
            glVertex3f(position.x, -size * .1, size * -.5);

            glVertex3f(position.x, -size * .1, size * -.5);
            glVertex3f(position.x, -size * .1, size * -.5);
            glVertex3f(position.x, -size * .1, size * -.5);
        }
        glEnd();
    }
    glPopMatrix();
}


void Wheel::calculate(const float bodySize) {
    float wheelDistance = bodySize / 2.0;

    float x = orientation == WheelOrientation::LEFT ? -wheelDistance : wheelDistance;

    position.x = x;
    position.y = 0;
    position.z = 0;
}
