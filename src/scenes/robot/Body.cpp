#include "Body.h"

Body::Body() {
    loadImage();
    model.load("res/blender_files/body/body.obj");
}

void Body::draw(const unsigned int frameIndex) {
    glPushMatrix();
    {
        glTranslatef(0, .25f, 0);
        Scene::draw(frameIndex);
        glScalef(.2f, .2f,.2f);

        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, imageId);
        model.draw();
        glDisable(GL_TEXTURE_2D);
    }
    glPopMatrix();
}

void Body::loadImage() {
    imageId = SOIL_load_OGL_texture("res/textures/robot/body.png",
                                       SOIL_LOAD_AUTO,
                                       SOIL_CREATE_NEW_ID,
                                       SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB);
}
