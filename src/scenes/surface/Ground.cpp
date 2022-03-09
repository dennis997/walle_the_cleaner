#include "Ground.h"

#include "../../vendor/glut.h"
#include "../../vendor/SOIL.h"


Ground::Ground() {
    float groundHeight = 0;
    float size = .9;

    init();
    calculate(size, groundHeight);
}

void Ground::draw(const unsigned int frameIndex) const {
    printDebug(.5);
    drawPlate();
    Scene::draw(frameIndex);
}

void Ground::init() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_NORMALIZE);
    glShadeModel(GL_SMOOTH);

    // Loading texture for groundplate from disk
    tex_2d = SOIL_load_OGL_texture("/res/textures/bottom_texture.jpg",
                                   SOIL_LOAD_AUTO,
                                   SOIL_CREATE_NEW_ID,
                                   SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT );
    glBindTexture(GL_TEXTURE_2D, tex_2d);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC0_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void Ground::drawPlate() const {
    glPushMatrix();
    {
        glEnable(GL_TEXTURE_2D);
        glBegin(GL_QUADS);
        {
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(_xz.x, _xz.y, _xz.z);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(xz.x, xz.y, xz.z);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(x_z.x, x_z.y, x_z.z);
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(_x_z.x, _x_z.y, _x_z.z);
        }
        glEnd();
        glDisable(GL_TEXTURE_2D);
    }
    glPopMatrix();
}

void Ground::calculate(float size, const float groundHeight) {
    float halfSize = size / 2;

    xz = VERTEX(halfSize, groundHeight, halfSize);
    _xz = VERTEX(-halfSize, groundHeight, halfSize);
    x_z = VERTEX(halfSize, groundHeight, -halfSize);
    _x_z = VERTEX(-halfSize, groundHeight, -halfSize);
}
