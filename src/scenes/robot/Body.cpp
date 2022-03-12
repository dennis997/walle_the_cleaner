#include "Body.h"
#include "../../vendor/SOIL.h"
#include "../../utilities/Parameters.h"


Body::Body() {
    Parameter* parameters = Parameter::getInstance();
    size = parameters->getRobotSize() / 8.f;

    loadImage();
}

void Body::draw(const unsigned int frameIndex) const {
    Scene::draw(frameIndex);

    glPushMatrix();
    {
        glColor3f(1, 1, 0);
        glTranslatef(0, size * 2, 0);
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, bodyImageId);

        glutSolidCube(.2f);

        glDisable(GL_TEXTURE_2D);
    }
    glPopMatrix();
}

void Body::loadImage() {
    bodyImageId = SOIL_load_OGL_texture("res/textures/robot/body.png",
                                       SOIL_LOAD_AUTO,
                                       SOIL_CREATE_NEW_ID,
                                       SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB);
}
