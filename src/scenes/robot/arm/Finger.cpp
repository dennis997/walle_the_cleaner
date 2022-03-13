#include "Finger.h"

#include "../../../vendor/glut.h"
#include "LowerArm.h"

Finger::Finger() {
    model.load("res/blender_files/finger/finger.obj");
    loadImage();
    calculate();
}

void Finger::draw(const unsigned int frameIndex) const {
    Scene::draw(frameIndex);

    float armLength = dynamic_cast<const LowerArm*>(parent)->getArmLength();

    glPushMatrix();
    {
        glTranslatef(armLength + .15f, position.y, position.z);
        glRotatef(90, 1.f, 0.f, 0.f);
        glRotatef(10, 0.f, 0.f, 1.f);

        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, eyeImageId);
        model.draw();
        glBindTexture(GL_TEXTURE_2D, 0);
        glDisable(GL_TEXTURE_2D);
    }
    glPopMatrix();

}


void Finger::loadImage() {
    eyeImageId = SOIL_load_OGL_texture("res/textures/robot/body.png",
                                       SOIL_LOAD_AUTO,
                                       SOIL_CREATE_NEW_ID,
                                       SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB);
}

void Finger::calculate() {
    position = glm::vec3(0.f, 0.f,-.1f);
}
