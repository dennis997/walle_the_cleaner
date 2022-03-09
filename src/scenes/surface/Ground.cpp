#include "Ground.h"

#include "../../vendor/glut.h"
#include "../../vendor/SOIL.h"

Ground::Ground() {
    float groundHeight = 0;
    float size = 5;

    calculate(size, groundHeight);

    surfaceImage = SOIL_load_OGL_texture("sun.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,
                                   SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB |
                                   SOIL_FLAG_COMPRESS_TO_DXT);

    glBindTexture(GL_TEXTURE_2D, surfaceImage);
}

void Ground::draw(const unsigned int frameIndex) const {
    drawDebug(1);
    drawPlate();
    Scene::draw(frameIndex);
}

void Ground::drawPlate() const {
    glPushMatrix();
    {
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

void Ground::calculate(float size, const float groundHeight) {
    float halfSize = size / 2;

    xz = VERTEX(halfSize, groundHeight, halfSize);
    _xz = VERTEX(-halfSize, groundHeight, halfSize);
    x_z = VERTEX(halfSize, groundHeight, -halfSize);
    _x_z = VERTEX(-halfSize, groundHeight, -halfSize);
}
