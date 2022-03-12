#include "Arm.h"

#include "../../vendor/glut.h"
#include "../../utilities/Parameters.h"


Arm::Arm(ArmSide armSide): orientation(armSide) {
    Parameter* parameters = Parameter::getInstance();
    width = parameters->getRobotSize() / 10.f;
    length = parameters->getRobotSize() / 3.f;

    calculate(parameters->getRobotSize());
}

void Arm::draw(unsigned int frameIndex) const {
    Scene::draw(frameIndex);

    glPushMatrix();
    {
        glColor3f(0,1,0);
        glTranslatef(position.x, position.y, position.z);
        glBegin(GL_QUADS);
        {
            // lower long side
            glVertex3f(0,0,0);
            glVertex3f(0,0,length);
            glVertex3f(width,0,length);
            glVertex3f(width,0,0);

            // upper long side
            glVertex3f(0,width,0);
            glVertex3f(0,width,length);
            glVertex3f(width,width,length);
            glVertex3f(width,width,0);
        }
        glEnd();
    }
    glPopMatrix();
}


void Arm::calculate(const float roboterSize) {
    float armDistance = roboterSize / 4.f;

    float x = orientation == ArmSide::LEFT ? -armDistance : armDistance;

    position.x = x;
    position.y = roboterSize / 2.f;
    position.z = 0;
}
