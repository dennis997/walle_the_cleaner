#include "Eye.h"

#include "../../vendor/glut.h"
#include "../../model/animation/Translate.h"
#include "../../model/animation/Rotate.h"

Eye::Eye(Side eyeSide) {
    orientation = eyeSide;

    std::string filename = "res/blender_files/eye/";
    filename.append(orientation == Side::LEFT ? "eye_left.obj" : "eye_right.obj");

    calculate();
    model.load(filename.c_str());
    loadImage();
    initAnimation();
}

void Eye::draw(const unsigned int frameIndex) {
    Scene::draw(frameIndex);

    glPushMatrix();
    {
        glScalef(.2f, .2f, .2f);
        glTranslatef(position.x, position.y, position.z);

        glRotatef(90,1.f, 0.f, 0.f);
        glRotatef(270,0.f, 1.f, 0.f);
        glRotatef(100,0.f, 0.f, 1.f);


        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, eyeImageId);
        model.draw();
        glBindTexture(GL_TEXTURE_2D, 0);
        glDisable(GL_TEXTURE_2D);
    }
    glPopMatrix();

}


void Eye::loadImage() {
    eyeImageId = SOIL_load_OGL_texture("res/textures/robot/body.png",
                                        SOIL_LOAD_AUTO,
                                        SOIL_CREATE_NEW_ID,
                                        SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB);
}


void Eye::calculate() {
    float eyeDistance = .4f;
    float x = orientation == Side::LEFT ? -eyeDistance : eyeDistance;

    position = glm::vec3(x, .8f, 0.3f);
}

void Eye::initAnimation() {
    Step* firstStep = new Step(new Rotate(10, glm::vec3(0.f, .0f, orientation == Side::LEFT ? 1.f : .5f)), 500.f, 750.f);

    idleAnimation.addAnimationStep(firstStep);
}
