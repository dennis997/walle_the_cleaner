#include "TrashCube.h"

#include "../../vendor/glut.h"
#include "../../vendor/SOIL.h"

TrashCube::TrashCube(float x, float y, float z) {
    this->position = glm::vec3(x,y,z);
    model.load("res/blender_files/body/body.obj");
    loadImage();
}

void TrashCube::draw(const unsigned int frameIndex) {
    glPushMatrix();
    {
        glTranslatef(position.x,position.y,position.z);
        Scene::draw(frameIndex);
        glScalef(.18f, .18f,.18f);
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, imageId);
        model.draw();
        glBindTexture(GL_TEXTURE_2D, 0);
        glDisable(GL_TEXTURE_2D);
    }
    glPopMatrix();
}

const glm::vec3 &TrashCube::getPosition() const {
    return position;
}

void TrashCube::setPosition(const glm::vec3 &position) {
    TrashCube::position = position;
}


void TrashCube::loadImage() {
    imageId = SOIL_load_OGL_texture("res/textures/trash.png",
                                    SOIL_LOAD_AUTO,
                                    SOIL_CREATE_NEW_ID,
                                    SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB);
}
