#include "LowerArm.h"

#include "../../../vendor/glut.h"
#include "../../../utilities/Parameters.h"

LowerArm::LowerArm(Side armSide) {
    Parameter* parameters = Parameter::getInstance();
    size = parameters->getRobotSize();

    orientation = armSide;

    calculate();
    model.load("res/blender_files/lower_arm/lower_arm.obj");
    loadImage();
}

void LowerArm::draw(const unsigned int frameIndex) const {
    Scene::draw(frameIndex);

    glPushMatrix();
    {
        glScalef(.2f, .2f, .2f);
        glTranslatef(position.x, position.y, position.z);

        glRotatef(90,orientation == Side::LEFT ? 1 : -1, 0.f, 0.f);
        glRotatef(90,0.f, 1.f, 0.f);
        glRotatef(90,0.f, 0.f, orientation == Side::LEFT ? 1 : -1);


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
    float wheelDistance = 0.f;
    float x = orientation == Side::LEFT ? -wheelDistance : wheelDistance;

    position = glm::vec3(x, 0.f, 0.f);
}