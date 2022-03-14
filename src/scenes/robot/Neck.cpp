#include "Neck.h"

#include "../../vendor/glut.h"
#include "../../utilities/Parameters.h"

Neck::Neck() {
    model.load("res/blender_files/neck/neck.obj");
    loadImage();

    calculate();
}

void Neck::draw(const unsigned int frameIndex) {
    glPushMatrix();
    {
        glTranslatef(position.x, position.y, position.z);
        Scene::draw(frameIndex);
        glScalef(.2f, .2f, .2f);
        glRotatef(270,0.f, 1.f, 0.f);

        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, neckImageId);
        model.draw();
        glBindTexture(GL_TEXTURE_2D, 0);
        glDisable(GL_TEXTURE_2D);
    }
    glPopMatrix();

}


void Neck::loadImage() {
    neckImageId = SOIL_load_OGL_texture("res/textures/robot/body.png",
                                        SOIL_LOAD_AUTO,
                                        SOIL_CREATE_NEW_ID,
                                        SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB);
}

void Neck::calculate() {
    position = glm::vec3(0.f, .16f, 0.f);
}
