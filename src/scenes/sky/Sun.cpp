#include "Sun.h"
#include "../../vendor/glut.h"

#include "../../utilities/Parameters.h"
#include "../../vendor/SOIL.h"

Sun::Sun() {
    radius = .3;

    Parameter* parameters = Parameter::getInstance();

    calculate(parameters->getFieldSize());
    loadImage();
}

void Sun::draw(unsigned int frameIndex) const {
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
        gluQuadricNormals(quadric, GLU_SMOOTH);	// Create Smooth Normals

        glTranslatef(position.x, position.y, position.z);

        glBindTexture(GL_TEXTURE_2D, sunImageId);
        glEnable(GL_TEXTURE_2D);

        gluSphere(quadric, radius, 30, 30);

        glDisable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, 0);
    }
    glPopMatrix();
}

void Sun::calculate(const int size) {
    position.x = size / 2;
    position.y = 2;
    position.z = -3;
}

void Sun::loadImage() {
    sunImageId = SOIL_load_OGL_texture("res/textures/inferno.png",
                                         SOIL_LOAD_AUTO,
                                         SOIL_CREATE_NEW_ID,
                                         SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB);
}
