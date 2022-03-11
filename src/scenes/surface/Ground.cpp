#include "Ground.h"

#include "../../vendor/glut.h"
#include "../../vendor/SOIL.h"

Ground::Ground() {
    float groundHeight = 0;
    float size = 5;

    calculate(size, groundHeight);
}

void Ground::draw(const unsigned int frameIndex) const {
    drawDebug(1);
    drawPlate();
    Scene::draw(frameIndex);
}

void Ground::drawPlate() const {
    glPushMatrix();
    {
        glColor3f(1, 1, 1);

        glBegin(GL_QUADS);
        {
            glTexCoord2f(0, 0);
            glVertex3f(_xz.x, _xz.y, _xz.z);
            glTexCoord2f(1, 0);
            glVertex3f(xz.x, xz.y, xz.z);
            glTexCoord2f(1, 1);
            glVertex3f(x_z.x, x_z.y, x_z.z);
            glTexCoord2f(0, 1);
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
