#include "Eye.h"

#include "../../vendor/glut.h"
#include "../../utilities/Parameters.h"

Eye::Eye(Side eyeSide) {
    Parameter* parameters = Parameter::getInstance();
    size = parameters->getRobotSize();

    orientation = eyeSide;

    calculate();
    model.load("res/blender_files/eye/eye.obj");
    loadImage();
}

void Eye::draw(const unsigned int frameIndex) const {
    Scene::draw(frameIndex);

    glPushMatrix();
    {
        glScalef(.2f, .2f, .2f);
        glTranslatef(position.x, position.y, position.z);

        glRotatef(90,orientation == Side::LEFT ? 1 : -1, 0.f, 0.f);
        glRotatef(270,0.f, orientation == Side::LEFT ? -1 : 1, 0.f);
        glRotatef(90,0.f, 0.f, orientation == Side::LEFT ? 1 : -1);

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
    float wheelDistance = .4f;
    float x = orientation == Side::LEFT ? -wheelDistance : wheelDistance;

    position = glm::vec3(x, .8f, 0.f);
}