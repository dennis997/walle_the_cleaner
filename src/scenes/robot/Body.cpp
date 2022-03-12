#include "Body.h"


#include "../../vendor/SOIL.h"
#include "../../utilities/Parameters.h"

GLuint vboId = 0;                   // ID of VBO for vertex arrays
GLfloat vertices[] = {1, 1, 1, -1, 1, 1, -1, -1, 1,      // v0-v1-v2 (front)
                      -1, -1, 1, 1, -1, 1, 1, 1, 1,      // v2-v3-v0

                      1, 1, 1, 1, -1, 1, 1, -1, -1,      // v0-v3-v4 (right)
                      1, -1, -1, 1, 1, -1, 1, 1, 1,      // v4-v5-v0

                      1, 1, 1, 1, 1, -1, -1, 1, -1,      // v0-v5-v6 (top)
                      -1, 1, -1, -1, 1, 1, 1, 1, 1,      // v6-v1-v0

                      -1, 1, 1, -1, 1, -1, -1, -1, -1,      // v1-v6-v7 (left)
                      -1, -1, -1, -1, -1, 1, -1, 1, 1,      // v7-v2-v1

                      -1, -1, -1, 1, -1, -1, 1, -1, 1,      // v7-v4-v3 (bottom)
                      1, -1, 1, -1, -1, 1, -1, -1, -1,      // v3-v2-v7

                      1, -1, -1, -1, -1, -1, -1, 1, -1,      // v4-v7-v6 (back)
                      -1, 1, -1, 1, 1, -1, 1, -1, -1};    // v6-v5-v4

// normal array
GLfloat normals[] = {0, 0, 1, 0, 0, 1, 0, 0, 1,      // v0-v1-v2 (front)
                     0, 0, 1, 0, 0, 1, 0, 0, 1,      // v2-v3-v0

                     1, 0, 0, 1, 0, 0, 1, 0, 0,      // v0-v3-v4 (right)
                     1, 0, 0, 1, 0, 0, 1, 0, 0,      // v4-v5-v0

                     0, 1, 0, 0, 1, 0, 0, 1, 0,      // v0-v5-v6 (top)
                     0, 1, 0, 0, 1, 0, 0, 1, 0,      // v6-v1-v0

                     -1, 0, 0, -1, 0, 0, -1, 0, 0,      // v1-v6-v7 (left)
                     -1, 0, 0, -1, 0, 0, -1, 0, 0,      // v7-v2-v1

                     0, -1, 0, 0, -1, 0, 0, -1, 0,      // v7-v4-v3 (bottom)
                     0, -1, 0, 0, -1, 0, 0, -1, 0,      // v3-v2-v7

                     0, 0, -1, 0, 0, -1, 0, 0, -1,      // v4-v7-v6 (back)
                     0, 0, -1, 0, 0, -1, 0, 0, -1};    // v6-v5-v4

// color array
GLfloat colors[] = {1, 1, 1, 1, 1, 0, 1, 0, 0,      // v0-v1-v2 (front)
                    1, 0, 0, 1, 0, 1, 1, 1, 1,      // v2-v3-v0

                    1, 1, 1, 1, 0, 1, 0, 0, 1,      // v0-v3-v4 (right)
                    0, 0, 1, 0, 1, 1, 1, 1, 1,      // v4-v5-v0

                    1, 1, 1, 0, 1, 1, 0, 1, 0,      // v0-v5-v6 (top)
                    0, 1, 0, 1, 1, 0, 1, 1, 1,      // v6-v1-v0

                    1, 1, 0, 0, 1, 0, 0, 0, 0,      // v1-v6-v7 (left)
                    0, 0, 0, 1, 0, 0, 1, 1, 0,      // v7-v2-v1

                    0, 0, 0, 0, 0, 1, 1, 0, 1,      // v7-v4-v3 (bottom)
                    1, 0, 1, 1, 0, 0, 0, 0, 0,      // v3-v2-v7

                    0, 0, 1, 0, 0, 0, 0, 1, 0,      // v4-v7-v6 (back)
                    0, 1, 0, 0, 1, 1, 0, 0, 1};    // v6-v5-v4



Body::Body() {
    Parameter* parameters = Parameter::getInstance();
    size = parameters->getRobotSize() / 8.f;

    loadImage();
    calculate();
}

void Body::draw(const unsigned int frameIndex) const {
    Scene::draw(frameIndex);

    glPushMatrix();
    {
        glColor3f(1, 1, 0);
        glTranslatef(0, size * 2, 0);
        glEnable(GL_TEXTURE_2D);
        //glBindTexture(GL_TEXTURE_2D, bodyImageId);

        glBindBufferARB(GL_ARRAY_BUFFER_ARB, vboId);

        glEnableClientState(GL_NORMAL_ARRAY);
        glEnableClientState(GL_COLOR_ARRAY);
        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);

        glNormalPointer(GL_FLOAT, 0, (void *) sizeof(vertices));
        glColorPointer(3, GL_FLOAT, 0, (void *) (sizeof(vertices) + sizeof(normals)));
        glVertexPointer(3, GL_FLOAT, 0, 0);

        glDrawArrays(GL_TRIANGLES, 0, 36);

        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_COLOR_ARRAY);
        glDisableClientState(GL_NORMAL_ARRAY);
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);

        glBindBufferARB(GL_ARRAY_BUFFER_ARB, 0);


        glBindTexture(GL_TEXTURE_2D, 0);
        glDisable(GL_TEXTURE_2D);
    }
    glPopMatrix();
}

void Body::loadImage() {
    bodyImageId = SOIL_load_OGL_texture("res/textures/robot/body.png",
                                       SOIL_LOAD_AUTO,
                                       SOIL_CREATE_NEW_ID,
                                       SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB);
}


void Body::calculate() {
    GLfloat _vertices[] = {1, 1, 1, -1, 1, 1, -1, -1, 1,      // v0-v1-v2 (front)
                          -1, -1, 1, 1, -1, 1, 1, 1, 1,      // v2-v3-v0

                          1, 1, 1, 1, -1, 1, 1, -1, -1,      // v0-v3-v4 (right)
                          1, -1, -1, 1, 1, -1, 1, 1, 1,      // v4-v5-v0

                          1, 1, 1, 1, 1, -1, -1, 1, -1,      // v0-v5-v6 (top)
                          -1, 1, -1, -1, 1, 1, 1, 1, 1,      // v6-v1-v0

                          -1, 1, 1, -1, 1, -1, -1, -1, -1,      // v1-v6-v7 (left)
                          -1, -1, -1, -1, -1, 1, -1, 1, 1,      // v7-v2-v1

                          -1, -1, -1, 1, -1, -1, 1, -1, 1,      // v7-v4-v3 (bottom)
                          1, -1, 1, -1, -1, 1, -1, -1, -1,      // v3-v2-v7

                          1, -1, -1, -1, -1, -1, -1, 1, -1,      // v4-v7-v6 (back)
                          -1, 1, -1, 1, 1, -1, 1, -1, -1};    // v6-v5-v4

// normal array
    GLfloat normals[] = {0, 0, 1, 0, 0, 1, 0, 0, 1,      // v0-v1-v2 (front)
                         0, 0, 1, 0, 0, 1, 0, 0, 1,      // v2-v3-v0

                         1, 0, 0, 1, 0, 0, 1, 0, 0,      // v0-v3-v4 (right)
                         1, 0, 0, 1, 0, 0, 1, 0, 0,      // v4-v5-v0

                         0, 1, 0, 0, 1, 0, 0, 1, 0,      // v0-v5-v6 (top)
                         0, 1, 0, 0, 1, 0, 0, 1, 0,      // v6-v1-v0

                         -1, 0, 0, -1, 0, 0, -1, 0, 0,      // v1-v6-v7 (left)
                         -1, 0, 0, -1, 0, 0, -1, 0, 0,      // v7-v2-v1

                         0, -1, 0, 0, -1, 0, 0, -1, 0,      // v7-v4-v3 (bottom)
                         0, -1, 0, 0, -1, 0, 0, -1, 0,      // v3-v2-v7

                         0, 0, -1, 0, 0, -1, 0, 0, -1,      // v4-v7-v6 (back)
                         0, 0, -1, 0, 0, -1, 0, 0, -1};    // v6-v5-v4

// color array
    GLfloat colors[] = {1, 1, 1, 1, 1, 0, 1, 0, 0,      // v0-v1-v2 (front)
                        1, 0, 0, 1, 0, 1, 1, 1, 1,      // v2-v3-v0

                        1, 1, 1, 1, 0, 1, 0, 0, 1,      // v0-v3-v4 (right)
                        0, 0, 1, 0, 1, 1, 1, 1, 1,      // v4-v5-v0

                        1, 1, 1, 0, 1, 1, 0, 1, 0,      // v0-v5-v6 (top)
                        0, 1, 0, 1, 1, 0, 1, 1, 1,      // v6-v1-v0

                        1, 1, 0, 0, 1, 0, 0, 0, 0,      // v1-v6-v7 (left)
                        0, 0, 0, 1, 0, 0, 1, 1, 0,      // v7-v2-v1

                        0, 0, 0, 0, 0, 1, 1, 0, 1,      // v7-v4-v3 (bottom)
                        1, 0, 1, 1, 0, 0, 0, 0, 0,      // v3-v2-v7

                        0, 0, 1, 0, 0, 0, 0, 1, 0,      // v4-v7-v6 (back)
                        0, 1, 0, 0, 1, 1, 0, 0, 1};    // v6-v5-v4

    glGenBuffersARB(1, &vboId);
    glBindBufferARB(GL_ARRAY_BUFFER_ARB, vboId);
    glBufferDataARB(GL_ARRAY_BUFFER_ARB, sizeof(vertices) + sizeof(normals) + sizeof(colors), 0, GL_STATIC_DRAW_ARB);
    glBufferSubDataARB(GL_ARRAY_BUFFER_ARB, 0, sizeof(vertices),vertices);                             // copy vertices starting from 0 offest
    glBufferSubDataARB(GL_ARRAY_BUFFER_ARB, sizeof(vertices), sizeof(normals), normals);                // copy normals after vertices
    glBufferSubDataARB(GL_ARRAY_BUFFER_ARB, sizeof(vertices) + sizeof(normals), sizeof(colors),colors);  // copy colours after normals
}
