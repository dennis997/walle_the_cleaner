#include "Ground.h"
#include "../../vendor/SOIL.h"

Ground::Ground() {
    groundHeight = 0;
    groundSize = 10;

    calculate(groundSize, groundHeight);
    loadImage();
}

void Ground::draw(const unsigned int frameIndex) const {
    drawDebug(1);
    drawPlate();
    Scene::draw(frameIndex);
}

void Ground::loadImage() {
    surfaceImage = SOIL_load_OGL_texture("res/textures/bottom_texture.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,
                                         SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB |
                                         SOIL_FLAG_COMPRESS_TO_DXT);

    glBindTexture(GL_TEXTURE_2D, surfaceImage);
}

void Ground::drawPlate() const {
    glPushMatrix();
    {
        glClearColor(0.0, 0.0, 0.4, 1.0);
        glColor3f(1, 1, 1);

        glEnable(GL_TEXTURE_2D);
        glBegin(GL_QUADS);
        {
            glTexCoord2f(0, 0);
            glVertex3f(_xz.x, _xz.y, _xz.z);
            glTexCoord2f(1, 0);
            glVertex3f(xz.x, xz.y, xz.z);
            glTexCoord2f(1, 1);
            glVertex3f(x_z.x, x_z.y, x_z.z);
            glTexCoord2f(0, 1);
            glVertex3f(_x_z.x, _x_z.y, _x_z.z);
        }
        glEnd();
        glDisable(GL_TEXTURE_2D);
    }
    glPopMatrix();
}

void Ground::calculate(float groundSize, const float groundHeight) {
    float halfSize = groundSize / 2;

    xz = VERTEX(halfSize, groundHeight, halfSize);
    _xz = VERTEX(-halfSize, groundHeight, halfSize);
    x_z = VERTEX(halfSize, groundHeight, -halfSize);
    _x_z = VERTEX(-halfSize, groundHeight, -halfSize);
}

std::list<VERTEX> Ground::getCoordinates() const {
    return std::list<VERTEX>{xz, x_z, _xz, _x_z};
}

float Ground::getGroundSize() const {
    return groundSize;
}