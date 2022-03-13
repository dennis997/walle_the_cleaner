#include "Finger.h"

#include "../../vendor/glut.h"
#include "../../utilities/Parameters.h"

Finger::Finger(Side eyeSide) {
    Parameter* parameters = Parameter::getInstance();
    size = parameters->getRobotSize();

    orientation = eyeSide;

    calculate();
    model.load("res/blender_files/finger/finger.obj");
    loadImage();
}

void Finger::draw(const unsigned int frameIndex) const {
    Scene::draw(frameIndex);

    glPushMatrix();
    {
        glScalef(.2f, .2f, .2f);
        glTranslatef(position.x, position.y, position.z);
        glRotatef(180,1.f, 0.f, 0.f);
        glRotatef(270,0.f, 1.f, 0.f);
        glRotatef(180,0.f, 0.f, 1.f);


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
    float wheelDistance = size / 2.f;
    float x = orientation == Side::LEFT ? -wheelDistance : wheelDistance;

    position = glm::vec3(0, -0.1f, 0.8f);
}