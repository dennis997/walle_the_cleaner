#include "Wheel.h"

#include "../../vendor/glut.h"
#include "../../utilities/Parameters.h"

Wheel::Wheel(const WheelSide orientation): orientation(orientation) {
    Parameter* parameters = Parameter::getInstance();
    size = parameters->getRobotSize() / 6.f;

    calculate(parameters->getRobotSize());
    model.load("res/blender_files/Wheel.obj");
    loadImage();
}

void Wheel::draw(unsigned int frameIndex) const {
    glPushMatrix();
    {
        glColor3f(.44, .47, .49);
        glScalef(.2f, .2f, .2f);
        glTranslatef(position.x, position.y, position.z);
        glRotatef(90,1.f, 0.f, 0.f);
        glRotatef(180,0.f, 1.f, 0.f);
        glRotatef(90,0.f, 0.f, orientation == WheelSide::LEFT ? 1 : -1);

        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, wheelImgId);
        model.draw();
        glBindTexture(GL_TEXTURE_2D, 0);
        glDisable(GL_TEXTURE_2D);
    }
    glPopMatrix();
}


void Wheel::calculate(const float roboterSize) {
    float wheelDistance = roboterSize / 2.f;

    float x = orientation == WheelSide::LEFT ? -wheelDistance : wheelDistance;

    position.x = x;
    position.y = .3f;
    position.z = 0;
}

void Wheel::loadImage() {
    wheelImgId = SOIL_load_OGL_texture("res/textures/inferno.png",
                                       SOIL_LOAD_AUTO,
                                       SOIL_CREATE_NEW_ID,
                                       SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB);
}
