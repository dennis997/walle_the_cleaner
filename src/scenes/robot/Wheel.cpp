#include "Wheel.h"

#include "../../vendor/glut.h"

Wheel::Wheel(const Side orientation): orientation(orientation) {
    calculate();
    model.load("res/blender_files/Wheel.obj");
    loadImage();
}

void Wheel::draw(unsigned int frameIndex) const {
    Scene::draw(frameIndex);

    glPushMatrix();
    {
        glColor3f(.44, .47, .49);
        glScalef(.2f, .2f, .2f);
        glTranslatef(position.x, position.y, position.z);
        glRotatef(90,1.f, 0.f, 0.f);
        glRotatef(180,0.f, 1.f, 0.f);
        glRotatef(90,0.f, 0.f, orientation == Side::LEFT ? 1 : -1);

        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, wheelImgId);
        model.draw();
        glBindTexture(GL_TEXTURE_2D, 0);
        glDisable(GL_TEXTURE_2D);
    }
    glPopMatrix();
}


void Wheel::loadImage() {
    wheelImgId = SOIL_load_OGL_texture("res/textures/robot/chains.png",
                                       SOIL_LOAD_AUTO,
                                       SOIL_CREATE_NEW_ID,
                                       SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB);
}


void Wheel::calculate() {
    float wheelDistance = .8f;
    float x = orientation == Side::LEFT ? -wheelDistance : wheelDistance;

    position = glm::vec3(x, 0.1f, 0.f);
}
