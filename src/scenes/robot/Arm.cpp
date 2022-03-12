#include "Arm.h"

#include "../../vendor/glut.h"
#include "../../utilities/Parameters.h"


Arm::Arm(ArmSide armSide): orientation(armSide) {
    Parameter* parameters = Parameter::getInstance();
    width = .05f;
    length = parameters->getRobotSize() / 3.f;

    calculate(parameters->getRobotSize());
}

void Arm::draw(unsigned int frameIndex) const {
    Scene::draw(frameIndex);

    glPushMatrix();
    {
        GLfloat light_ambient[] = { .2f, .2f, .2f, 1.f }; // intensity of light
        GLfloat light_diffuse[] = { 0.960f, 0.1, 0.1, 1.f }; // color of light
        GLfloat light_specular[] = { 1.f, 1.f, 1.f, 1.f }; // color of light

        glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
        glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

        glColor3f(0,1,0);
        glTranslatef(position.x, position.y, position.z);
        glBegin(GL_QUADS);
        {
            // lower side
            glNormal3b(0.f, -1.f, 0.f);
            glVertex3f(0,0,0);
            glVertex3f(0,0,length);
            glVertex3f(width,0,length);
            glVertex3f(width,0,0);

            // upper side
            glNormal3b(0.f, 1.f, 0.f);
            glVertex3f(0,width,0);
            glVertex3f(0,width,length);
            glVertex3f(width,width,length);
            glVertex3f(width,width,0);

            // right side
            glNormal3b(1.f, 0.f, 0.f);
            glVertex3f(0,0,0);
            glVertex3f(0,width,0);
            glVertex3f(0,width,length);
            glVertex3f(0,0,length);

            // left side
            glNormal3b(-1.f, 0.f, 0.f);
            glVertex3f(width,0,0);
            glVertex3f(width,width,0);
            glVertex3f(width,width,length);
            glVertex3f(width,0,length);

            // short side front
            glNormal3b(0.f, 0.f, -1.f);
            glVertex3f(0,0,length);
            glVertex3f(width,0,length);
            glVertex3f(width,width,length);
            glVertex3f(0,width,length);

            // short side back
            glNormal3b(0.f, 0.f, 1.f);
            glVertex3f(0,0,0);
            glVertex3f(width,0,0);
            glVertex3f(width,width,0);
            glVertex3f(0,width,0);
        }
        glEnd();
    }
    glPopMatrix();
}


void Arm::calculate(const float roboterSize) {
    float x = roboterSize / 8.f;

    if (orientation == ArmSide::LEFT) {
        x = (x + width) * -1.f;
    }

    position.x = x;
    position.y = roboterSize / 4.f;
    position.z = 0;
}
