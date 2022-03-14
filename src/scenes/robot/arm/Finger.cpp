#include "Finger.h"

#include "../../../vendor/glut.h"
#include "LowerArm.h"
#include "../../../model/animation/Rotate.h"
#include "../../../model/animation/Translate.h"


Finger::Finger(const Side side): orientation(side) {
    model.load("res/blender_files/finger/finger.obj");
    loadImage();
    calculate();
    initAnimation();
}

void Finger::draw(const unsigned int frameIndex) {
    float armLength = dynamic_cast<const LowerArm*>(parent)->getArmLength() + .2f;

    glPushMatrix();
    {
        glTranslatef(armLength, position.y, position.z);
        glRotatef(90, 1.f, 0.f, 0.f);
        glRotatef(10, 0.f, 0.f, 1.f);
        Scene::draw(frameIndex);

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

void Finger::initAnimation() {
    Step* firstStep = new Step(new Translate(glm::vec3(0.f, 0.2f, .0f)), 100.f, 2000.f);
    Step* secondStep = new Step(new Rotate(90, glm::vec3(0.f, .0f, 1.f)), 500.f, 2000.f);

    animationExecutor.addAnimationStep(firstStep);
    animationExecutor.addAnimationStep(secondStep);
}
