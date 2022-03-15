#include "Sun.h"
#include "../../vendor/glut.h"

#include "../../utilities/Parameters.h"
#include "../../vendor/SOIL.h"

Sun::Sun() {
    radius = .8;

    Parameter* parameters = Parameter::getInstance();
    fieldSize = parameters->getFieldSize();

    calculate();
    loadImage();
}

void Sun::draw(unsigned int frameIndex) {
    drawSun(frameIndex);
    Scene::draw(frameIndex);
}

void Sun::drawSun(unsigned int frameIndex) const {
    glPushMatrix();
    {
        glColor3f(1, 1, 1);

        GLUquadric* quadric = gluNewQuadric();
        gluQuadricOrientation(quadric, GLU_OUTSIDE);
        gluQuadricTexture(quadric, GL_TRUE);
        gluQuadricNormals(quadric, GLU_SMOOTH);

        glTranslatef(position.x, position.y, position.z);
        glRotatef(frameIndex / 4.f, 0.f, 1.f, 0.f);

        glBindTexture(GL_TEXTURE_2D, sunImageId);
        glEnable(GL_TEXTURE_2D);
        gluSphere(quadric, radius, 30, 30);
        glDisable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, 0);
    }
    glPopMatrix();
}

void Sun::calculate() {
    position.x = fieldSize / 4.f;
    position.y = 3.5;
    position.z = -3.f;
}

void Sun::loadImage() {
    sunImageId = SOIL_load_OGL_texture("res/textures/inferno.png",
                                         SOIL_LOAD_AUTO,
                                         SOIL_CREATE_NEW_ID,
                                         SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB);
}
