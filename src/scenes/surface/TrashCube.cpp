#include "TrashCube.h"

#include "../../vendor/glut.h"

void TrashCube::draw(const unsigned int frameIndex) const {
    glPushMatrix();
    {
        glColor3f(.3, .3, .3);
        glTranslated(-.1, .05, -.1);

        drawDebug(0.3);
        glutSolidCube(.1);
    }
    glPopMatrix();

    Scene::draw(frameIndex);
}
