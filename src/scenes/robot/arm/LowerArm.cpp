#include "LowerArm.h"

#include "../../../vendor/glut.h"
#include "../../../utilities/Parameters.h"

LowerArm::LowerArm() {
    armLength = .5f;

    calculate();
    model.load("res/blender_files/lower_arm/lower_arm.obj");
    loadImage();
}

void LowerArm::draw(const unsigned int frameIndex) const {
    glPushMatrix();
    {
        glScalef(.2f, .2f, .2f);
        glTranslatef(position.x, position.y, position.z);
        Scene::draw(frameIndex);

        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, imageId);
        model.draw();
        glBindTexture(GL_TEXTURE_2D, 0);
        glDisable(GL_TEXTURE_2D);
    }
    glPopMatrix();
}


void LowerArm::loadImage() {
    imageId = SOIL_load_OGL_texture("res/textures/robot/body.png",
                                       SOIL_LOAD_AUTO,
                                       SOIL_CREATE_NEW_ID,
                                       SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB);
}

void LowerArm::calculate() {
    position = glm::vec3(armLength, 0.f, 0.f);
}

float LowerArm::getArmLength() const {
    return armLength;
}
