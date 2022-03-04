#include "Ground.h"

#ifdef __APPLE__
/* Defined before OpenGL and GLUT includes to avoid deprecation messages */
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

Ground::Ground() {
    float groundHeight = 0;
    float size = .4;

    calculate(size, groundHeight);
}

void Ground::draw(const unsigned int frameIndex) const {
    printDebug(.5);
    drawPlate();
    Scene::draw(frameIndex);
}

void Ground::drawPlate() const {
    glPushMatrix();
    {
        glColor3f(0, .6, 0);
        glBegin(GL_QUADS);
        {
            glVertex3f(_xz.x, _xz.y, _xz.z);
            glVertex3f(xz.x, xz.y, xz.z);
            glVertex3f(x_z.x, x_z.y, x_z.z);
            glVertex3f(_x_z.x, _x_z.y, _x_z.z);
        }
        glEnd();
    }
    glPopMatrix();
}

void Ground::calculate(float size, const float groundHeight) {
    float halfSize = size / 2;

    xz = VERTEX(halfSize, groundHeight, halfSize);
    _xz = VERTEX(-halfSize, groundHeight, halfSize);
    x_z = VERTEX(halfSize, groundHeight, -halfSize);
    _x_z = VERTEX(-halfSize, groundHeight, -halfSize);
}
