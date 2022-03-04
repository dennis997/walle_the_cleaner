#include "TrashCube.h"
#include <GL/glut.h>

void TrashCube::draw(const unsigned int frameIndex) const {
    glPushMatrix();
    {
        glColor3f(.3, .3, .3);
        glTranslated(-.1, .05, -.1);

        printDebug(0.3);
        glutSolidCube(.1);
    }
    Scene::draw(frameIndex);
}
