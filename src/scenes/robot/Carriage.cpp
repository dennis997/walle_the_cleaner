#include "Carriage.h"

#include "../../vendor/glut.h"
#include "../../vendor/Cube.h"
#include "../../model/animation/Visibility.h"
#include "../../model/animation/Callback.h"
#include "../../utilities/Parameters.h"


Carriage::Carriage(Robot* robot, Surface* surface): visible{false}, robot{robot}, surface{surface} {
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

        if (robot->hasCube()) {
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D, imageId);
            Cube(trashCubeSize);
            glBindTexture(GL_TEXTURE_2D, 0);
            glDisable(GL_TEXTURE_2D);
        }
    }
    glPopMatrix();
}


void Carriage::loadImage() {
    imageId = SOIL_load_OGL_texture("res/textures/trash.png",
                                       SOIL_LOAD_AUTO,
                                       SOIL_CREATE_NEW_ID,
                                       SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB);
}


void Carriage::calculate() {
    position = glm::vec3(0.f, .3f, 0.3f);
}

void Carriage::initAnimation() {
    CallbackFunction callback{};
    callback.callback = [&](){
        surface->pickUpOrLayDown();
    };

    Step* secondStep = new Step(new Callback(callback), 30.f, 2600.f);
    grabAnimation.addAnimationStep(secondStep);
}
