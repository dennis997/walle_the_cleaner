#include "Ground.h"
#include "../../vendor/SOIL.h"

#include "../../utilities/Parameters.h"

Ground::Ground() {
    Parameter* parameters = Parameter::getInstance();

    groundHeight = 0;
    slices = 100;
    size = parameters->getFieldSize();

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
}

void Ground::drawPlate() const {
    glPushMatrix();
    {
        glColor3f(1,1,1);

        glBindTexture(GL_TEXTURE_2D, surfaceImage);
        glEnable(GL_TEXTURE_2D);

        glDisable(GL_LIGHT0);

        // divide ground into n slices
        float sliceSize = size / slices;
        for (float x = .0f; x < size - sliceSize; x += sliceSize) {
            for (float z = .0f; z < size - sliceSize; z += sliceSize) {
                glBegin(GL_TRIANGLE_STRIP);

                glNormal3f(0.0f, 1.0f, 0.0f);
                glTexCoord2f(x / size, z / size);
                glVertex3f(x, groundHeight, z);

                glTexCoord2f((x + sliceSize) / size, z / size);
                glVertex3f(x + sliceSize, groundHeight, z);

                glTexCoord2f(x / size, (z + sliceSize) / size);
                glVertex3f(x, groundHeight, z + sliceSize);

                glTexCoord2f((x + sliceSize) / size, (z + sliceSize) / size);
                glVertex3f(x + sliceSize, groundHeight, z + sliceSize);
                glEnd();
            }
        }

        glEnable(GL_LIGHT0);


        glDisable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, 0);
    }
    glPopMatrix();
}

void Ground::calculate(float groundSize, const float groundHeight) {
    xz = glm::vec3(groundSize, groundHeight, groundSize);
    _xz = glm::vec3(0, groundHeight, groundSize);
    x_z = glm::vec3(groundSize, groundHeight, 0);
    _x_z = glm::vec3(0, groundHeight, 0);
}