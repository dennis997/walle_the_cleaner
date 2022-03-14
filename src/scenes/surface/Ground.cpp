#include "Ground.h"
#include "../../vendor/SOIL.h"

#include "../../utilities/Parameters.h"

Ground::Ground() {
    Parameter* parameters = Parameter::getInstance();

    groundHeight = 0;
    slices = 100;
    groundSize = parameters->getFieldSize();
    undergroundSize = groundSize + 4;


    loadImage();
}

void Ground::draw(const unsigned int frameIndex) {
    drawDebug(1);
    drawPlate();
    Scene::draw(frameIndex);
}

void Ground::loadImage() {
    surfaceImage = SOIL_load_OGL_texture("res/textures/bottom_texture.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,
                                         SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB |
                                         SOIL_FLAG_COMPRESS_TO_DXT);

    lavaImage = SOIL_load_OGL_texture("res/textures/Lava.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,
                                      SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB |
                                      SOIL_FLAG_COMPRESS_TO_DXT);
}

void Ground::drawPlate() const {
    Parameter* parameter = Parameter::getInstance();
    float gap = parameter->getGapSize();

    glPushMatrix();
    {
        glColor3f(1,1,1);

        glBindTexture(GL_TEXTURE_2D, surfaceImage);
        glEnable(GL_TEXTURE_2D);

        glDisable(GL_LIGHT0);

        // divide ground into n slices
        float sliceSize = groundSize / slices;
        for (float x = .0f; x < groundSize - sliceSize; x += sliceSize) {
            for (float z = .0f; z < groundSize - sliceSize; z += sliceSize) {
                glBegin(GL_TRIANGLE_STRIP);

                glNormal3f(0.0f, 1.0f, 0.0f);
                glTexCoord2f(x / groundSize, z / groundSize);
                glVertex3f(x, groundHeight, z);

                glTexCoord2f((x + sliceSize) / groundSize, z / groundSize);
                glVertex3f(x + sliceSize, groundHeight, z);

                glTexCoord2f(x / groundSize, (z + sliceSize) / groundSize);
                glVertex3f(x, groundHeight, z + sliceSize);

                glTexCoord2f((x + sliceSize) / groundSize, (z + sliceSize) / groundSize);
                glVertex3f(x + sliceSize, groundHeight, z + sliceSize);
                glEnd();
            }
        }

        glEnable(GL_LIGHT0);

        glDisable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, 0);
    }
    glPopMatrix();


    // Underground Lava

    glPushMatrix();
    {
        glColor3f(1,1,1);

        glBindTexture(GL_TEXTURE_2D, lavaImage);
        glEnable(GL_TEXTURE_2D);
        glDisable(GL_LIGHT0);

        glBegin(GL_QUADS);

        glNormal3f(0.0f, 1.0f, 0.0f);

        glTexCoord2f(0.0, 0.0);
        glVertex3f(-gap, groundHeight - 0.5, -gap);

        glTexCoord2f(1.0, 0.0);
        glVertex3f(undergroundSize + gap, groundHeight - 0.5, - gap);

        glTexCoord2f(1.0, 1.0);
        glVertex3f(undergroundSize + gap, groundHeight - 0.5, undergroundSize + gap);

        glTexCoord2f(0.0, 1.0);
        glVertex3f(-gap, groundHeight - 0.5, undergroundSize + gap);

        glEnd();
    }


    glEnable(GL_LIGHT0);

    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    glPopMatrix();
}

void Ground::calculate(float groundSize, const float groundHeight) {
    xz = glm::vec3(groundSize, groundHeight, groundSize);
    _xz = glm::vec3(0, groundHeight, groundSize);
    x_z = glm::vec3(groundSize, groundHeight, 0);
    _x_z = glm::vec3(0, groundHeight, 0);
}