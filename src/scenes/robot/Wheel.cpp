#include "Wheel.h"

#include "../../vendor/glut.h"
#include "../../utilities/Parameters.h"

Wheel::Wheel(const WheelSide orientation): orientation(orientation) {
    Parameter* parameters = Parameter::getInstance();
    size = parameters->getRobotSize() / 6.f;

    calculate(parameters->getRobotSize());
    model.load("res/blender_files/Wheel.obj");
}

void Wheel::draw(unsigned int frameIndex) const {
    glPushMatrix();
    {
        glColor3f(.44, .47, .49);
        glTranslatef(position.x, position.y, position.z);
        model.draw();
    }
    glPopMatrix();
}


void Wheel::calculate(const float roboterSize) {
    float wheelDistance = roboterSize / 4.f;

    float x = orientation == WheelSide::LEFT ? -wheelDistance : wheelDistance;

    position.x = x;
    position.y = .1f;
    position.z = 0;
}
