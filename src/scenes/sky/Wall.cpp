#include "Wall.h"

#include "../../utilities/Parameters.h"
#include "../../vendor/glut.h"
#include "../../vendor/SOIL.h"
#include <string>

Wall::Wall(const WallSide wallSide) {
    Parameter *parameters = Parameter::getInstance();
    calculate(wallSide, parameters->getFieldSize());
    loadImage(wallSide);
}

void Wall::draw(unsigned int frameIndex) {
    glPushMatrix();
    {
        glColor3f(1, 1, 1);
        glBindTexture(GL_TEXTURE_2D, img_id);
        glEnable(GL_TEXTURE_2D);
        glTranslatef(0,-2,0);
        glBegin(GL_QUADS);
        {
            glNormal3f(0, 0, 0);
            glTexCoord2f(0, 0);
            glVertex3f(vertices[0], vertices[1], vertices[2]);
            glTexCoord2f(1, 0);
            glVertex3f(vertices[3], vertices[4], vertices[5]);
            glTexCoord2f(0, 1);
            glVertex3f(vertices[6], vertices[7], vertices[8]);
            glTexCoord2f(1, 1);
            glVertex3f(vertices[9], vertices[10], vertices[11]);
        }
        glEnd();

        glBindTexture(GL_TEXTURE_2D, 0);
        glDisable(GL_TEXTURE_2D);
    }
    glPopMatrix();

    Scene::draw(frameIndex);
}


void Wall::calculate(const WallSide wallSide, const float fieldSize) {
    float gap = 4;

    switch (wallSide) {
        case LEFT:
            vertices = {-gap, 0, -gap,
                        -gap, 0, gap + fieldSize,
                        -gap, fieldSize, gap + fieldSize,
                        -gap, fieldSize, -gap,
            };
            vertex_normal = glm::vec3(-1.f, .0f, .0f);
            break;
        case RIGHT:
            vertices = {gap + fieldSize, 0, -gap,
                        gap + fieldSize, 0, gap + fieldSize,
                        gap + fieldSize, fieldSize, gap + fieldSize,
                        gap + fieldSize, fieldSize, -gap,
            };
            vertex_normal = glm::vec3(1.f, .0f, .0f);
            break;
        case BACK:
            vertices = {-gap, 0, -gap,
                        gap + fieldSize, 0, -gap,
                        gap + fieldSize, fieldSize, -gap,
                        -gap, fieldSize, -gap,
            };
            vertex_normal = glm::vec3(.0f, .0f, 1.f);
            break;
        case FRONT:
            vertices = {-gap, 0, gap + fieldSize,
                        gap + fieldSize, 0, gap + fieldSize,
                        gap + fieldSize, fieldSize, gap + fieldSize,
                        -gap, fieldSize, gap + fieldSize,
            };
            vertex_normal = glm::vec3(.0f, 0.f, -1.f);
            break;
    }
}

void Wall::loadImage(const WallSide wallSide) {
    std::string imageName;

    switch (wallSide) {
        case LEFT:
            imageName = "left.png";
            break;
        case RIGHT:
            imageName = "right.png";
            break;
        case FRONT:
            imageName = "front.png";
            break;
        case BACK:
            imageName = "back.png";
            break;
    }

    imageName.insert(0, "res/textures/skybox/");

    img_id = SOIL_load_OGL_texture(imageName.c_str(), SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,
                                         SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_INVERT_Y |
                                         SOIL_FLAG_COMPRESS_TO_DXT);
}
