#include "UpperArm.h"

#include "../../../vendor/glut.h"
#include "../../../utilities/Parameters.h"
#include "../../../model/animation/Translate.h"
#include "../../../model/animation/Rotate.h"

UpperArm::UpperArm(Side armSide) {
    orientation = armSide;

    calculate();
    model.load("res/blender_files/upper_arm/upper_arm.obj");
    loadImage();

    initAnimation();
}

void UpperArm::draw(const unsigned int frameIndex) {
    glPushMatrix();
    {
        glTranslatef(position.x, position.y, position.z);

        glRotatef(90,1.f, 0.f, 0.f);
        glRotatef(180,0.f, 1.f, 0.f);
        glRotatef(90,0.f, 0.f, 1.f);

        Scene::draw(frameIndex);

        glScalef(.2f, .2f, .2f);

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
    float distance = .175f;
    float x = orientation == Side::LEFT ? -distance : distance;

    position = glm::vec3(x, .1f, 0.f);
}

void UpperArm::initAnimation() {
    Step* rotateArm = new Step(new Rotate(20, glm::vec3(0.f, 1.0f, .0f)), 1000.f, 1000.f);
    grabAnimation.addAnimationStep(rotateArm);

    Step* liftArm = new Step(new Rotate(60, glm::vec3(.0f,  -1.f, .0f)), 500.f, 0.f);
    idleAnimation.addAnimationStep(liftArm);
}

Side UpperArm::getOrientation() const {
    return orientation;
}
