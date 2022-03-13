#include "Neck.h"

#include "../../vendor/glut.h"
#include "../../utilities/Parameters.h"

Neck::Neck() {
    Parameter* parameters = Parameter::getInstance();
    size = parameters->getRobotSize();

    position = glm::vec3(0.f, size / 2.f, 0.f);
    model.load("res/blender_files/Wheel.obj");
    loadImage();
}

void Neck::draw(const unsigned int frameIndex) const {
    Scene::draw(frameIndex);

    glPushMatrix();
    {
        glScalef(.2f, .2f, .2f);
        glTranslatef(position.x, position.y, position.z);
        glRotatef(90,1.f, 0.f, 0.f);
        glRotatef(180,0.f, 1.f, 0.f);

        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, neckImageId);
        model.draw();
        glBindTexture(GL_TEXTURE_2D, 0);
        glDisable(GL_TEXTURE_2D);
    }
    glPopMatrix();

}


void Neck::loadImage() {
    neckImageId = SOIL_load_OGL_texture("res/textures/robot/body.png",
                                        SOIL_LOAD_AUTO,
                                        SOIL_CREATE_NEW_ID,
                                        SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB);
}
