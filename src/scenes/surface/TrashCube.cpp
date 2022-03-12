#include "TrashCube.h"

#include "../../vendor/glut.h"

void TrashCube::draw(const unsigned int frameIndex) const {
    Scene::draw(frameIndex);

    float x = 5;
    float y = 5;
    float z = 10;


    glPushMatrix();
    glTranslatef(x,y,z);
    glColor3f(1,1,1);
    glutSolidCube(.1);
    glPopMatrix();
}
