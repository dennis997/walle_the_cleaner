#include "Body.h"

#include "../../vendor/glut.h"

void Body::draw(const unsigned int frameIndex) const {
    Scene::draw(frameIndex);

    glPushMatrix();
    {
        glColor3f(1, 1, 0);
        glTranslatef(0, size / 1.5, 0);
        glutSolidCube(size);
    }
    glPopMatrix();
}

float Body::getSize() const {
    return size;
}
