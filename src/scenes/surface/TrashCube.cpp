#include "TrashCube.h"

#ifdef __APPLE__
/* Defined before OpenGL and GLUT includes to avoid deprecation messages */
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


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
