#include "Carriage.h"

#include "../../vendor/glut.h"
#include "../../vendor/Cube.h"
#include "../../model/animation/Visibility.h"
#include "../../utilities/Parameters.h"


Carriage::Carriage(): visible(false) {
    Parameter* parameters = Parameter::getInstance();
    trashCubeSize = parameters->getTrashCubeSize();

    calculate();
    loadImage();
    initAnimation();
}

void Carriage::draw(const unsigned int frameIndex) {
    Scene::draw(frameIndex);

    glPushMatrix();
    {
        glTranslatef(position.x, position.y, position.z);

        glEnable(GL_TEXTURE_2D);
        Cube(trashCubeSize);
        glBindTexture(GL_TEXTURE_2D, 0);
        glDisable(GL_TEXTURE_2D);
    }
    glPopMatrix();
}


void Carriage::loadImage() {
    imageId = SOIL_load_OGL_texture("res/textures/robot/body.png",
                                       SOIL_LOAD_AUTO,
                                       SOIL_CREATE_NEW_ID,
                                       SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB);
}


void Carriage::calculate() {
    position = glm::vec3(0.f, .3f, 0.3f);
}

void Carriage::initAnimation() {
    Step* firstStep = new Step(new Visibility, 30.f, 2300.f);

    animationExecutor.addAnimationStep(firstStep);
}
