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

void Ground::draw() const {
    printDebug(.5);
    drawPlate();
    Scene::draw();
}

void Ground::drawPlate() const {
    glPushMatrix();
    {
        glColor3f(0, .6, 0);
        glBegin(GL_QUADS);
        {
            glVertex3f(_xz.Position.x, _xz.Position.y, _xz.Position.z);
            glVertex3f(xz.Position.x, xz.Position.y, xz.Position.z);
            glVertex3f(x_z.Position.x, x_z.Position.y, x_z.Position.z);
            glVertex3f(_x_z.Position.x, _x_z.Position.y, _x_z.Position.z);
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
