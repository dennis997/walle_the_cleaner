#include "Body.h"

#include "../../vendor/glut.h"
#include "../../utilities/Parameters.h"

Body::Body() {
    Parameter* parameters = Parameter::getInstance();
    size = parameters->getRobotSize() / 4.f;
}


void Body::draw(const unsigned int frameIndex) const {
    Scene::draw(frameIndex);

    glPushMatrix();
    {
        glColor3f(1, 1, 0);
        glTranslatef(0, size / 1.3f, 0);
        glutSolidCube(size);
    }
    glPopMatrix();
}