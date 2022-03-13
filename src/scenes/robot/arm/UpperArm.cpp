#include "UpperArm.h"

#include "../../../vendor/glut.h"
#include "../../../utilities/Parameters.h"

UpperArm::UpperArm(Side armSide) {
    Parameter* parameters = Parameter::getInstance();
    size = parameters->getRobotSize();

    orientation = armSide;

    calculate();
    model.load("res/blender_files/upper_arm/upper_arm.obj");
    loadImage();
}

void UpperArm::draw(const unsigned int frameIndex) const {
    glPushMatrix();
    {
        glTranslatef(position.x, position.y, position.z);
        Scene::draw(frameIndex);
        glScalef(.05f, .05f, .05f);


        glRotatef(90,1.f, 0.f, 0.f);
        glRotatef(90,0.f, orientation == Side::LEFT ? -1 : 0, 0.f);
        glRotatef(90,0.f, 0.f, 1.f);



        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, imageId);
        model.draw();
        glBindTexture(GL_TEXTURE_2D, 0);
        glDisable(GL_TEXTURE_2D);
    }
    glPopMatrix();
}


void UpperArm::loadImage() {
    imageId = SOIL_load_OGL_texture("res/textures/robot/body.png",
                                       SOIL_LOAD_AUTO,
                                       SOIL_CREATE_NEW_ID,
                                       SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB);
}


void UpperArm::calculate() {
    float wheelDistance = .2f;
    float x = orientation == Side::LEFT ? -wheelDistance : wheelDistance;

    position = glm::vec3(x, .1f, 0.f);
}