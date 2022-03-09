#include "Sun.h"
#include "../../vendor/glut.h"

Sun::Sun() {
    radius = .15;
    setPosition();
}

void Sun::draw(unsigned int frameIndex) const {
    drawSun();
    drawLight();

    Scene::draw(frameIndex);
}

void Sun::drawSun() const {
    glPushMatrix();
    {
        glColor3f(.945, .952, .647);
        glTranslatef(position.x, position.y, position.z);
        gluSphere(gluNewQuadric(), radius, 40, 40);
    }
    glPopMatrix();
}

void Sun::setPosition() {
    position.x = .4;
    position.y = .5;
    position.z = -1;
}

void Sun::drawLight() const {
    GLfloat light_position[] = {position.x, position.y, 0, 1};
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
}
