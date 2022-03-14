#ifndef WALL_E_CUBE
#define WALL_E_CUBE

#include "../GL/freeglut.h"

inline void Cube(GLfloat size)
{
    // front side
    glBegin(GL_POLYGON);
    glNormal3f(0.0f, 0.0f, 1.0f);
    glTexCoord3f(-1.f, -1.f, 1.f);
    glVertex3f(-size / 2.0f, -size / 2.0f, +size / 2.0f);
    glTexCoord3f(1.f, -1.f, 1.f);
    glVertex3f(+size / 2.0f, -size / 2.0f, +size / 2.0f);
    glTexCoord3f(1.f, 1.f, 1.f);
    glVertex3f(+size / 2.0f, +size / 2.0f, +size / 2.0f);
    glTexCoord3f(-1.f, 1.f, 1.f);
    glVertex3f(-size / 2.0f, +size / 2.0f, +size / 2.0f);
    glEnd();


    glBegin(GL_POLYGON);   //Rechte Seite
    glNormal3f(1.0f, 0.0f, 0.0f);
    glTexCoord3f(1.f, -1.f, 1.f);
    glVertex3f(+size / 2.0f, -size / 2.0f, +size / 2.0f);
    glTexCoord3f(1.f, -1.f, -1.f);
    glVertex3f(+size / 2.0f, -size / 2.0f, -size / 2.0f);
    glTexCoord3f(1.f, 1.f, -1.f);
    glVertex3f(+size / 2.0f, +size / 2.0f, -size / 2.0f);
    glTexCoord3f(1.f, 1.f, 1.f);
    glVertex3f(+size / 2.0f, +size / 2.0f, +size / 2.0f);
    glEnd();


    glBegin(GL_POLYGON);   //Rueckseite
    glNormal3f(0.0f, 0.0f, -1.0f);
    glTexCoord3f(1.f, 1.f, -1.f);
    glVertex3f(+size / 2.0f, +size / 2.0f, -size / 2.0f);
    glTexCoord3f(1.f, -1.f, -1.f);
    glVertex3f(+size / 2.0f, -size / 2.0f, -size / 2.0f);
    glTexCoord3f(-1.f, -1.f, -1.f);
    glVertex3f(-size / 2.0f, -size / 2.0f, -size / 2.0f);
    glTexCoord3f(-1.f, 1.f, -1.f);
    glVertex3f(-size / 2.0f, +size / 2.0f, -size / 2.0f);
    glEnd();


    glBegin(GL_POLYGON);   //Linke Seite
    glNormal3f(-1.0f, 0.0f, 0.0f);
    glTexCoord3f(-1.f, 1.f, -1.f);
    glVertex3f(-size / 2.0f, +size / 2.0f, -size / 2.0f);
    glTexCoord3f(-1.f, -1.f, -1.f);
    glVertex3f(-size / 2.0f, -size / 2.0f, -size / 2.0f);
    glTexCoord3f(-1.f, -1.f, 1.f);
    glVertex3f(-size / 2.0f, -size / 2.0f, +size / 2.0f);
    glTexCoord3f(-1.f, 1.f, 1.f);
    glVertex3f(-size / 2.0f, +size / 2.0f, +size / 2.0f);
    glEnd();

    glBegin(GL_POLYGON);   //Deckflaeche
    glNormal3f(0.0f, 1.0f, 0.0f);
    glTexCoord3f(-1.f, 1.f, 1.f);
    glVertex3f(-size / 2.0f, +size / 2.0f, +size / 2.0f);
    glTexCoord3f(1.f, 1.f, 1.f);
    glVertex3f(+size / 2.0f, +size / 2.0f, +size / 2.0f);
    glTexCoord3f(1.f, 1.f, -1.f);
    glVertex3f(+size / 2.0f, +size / 2.0f, -size / 2.0f);
    glTexCoord3f(-1.f, 1.f, -1.f);
    glVertex3f(-size / 2.0f, +size / 2.0f, -size / 2.0f);
    glEnd();

    glBegin(GL_POLYGON);   //Bodenflaeche
    glNormal3f(0.0f, -1.0f, 0.0f);
    glTexCoord3f(-1.f, -1.f, -1.f);
    glVertex3f(-size / 2.0f, -size / 2.0f, -size / 2.0f);
    glTexCoord3f(1.f, -1.f, -1.f);
    glVertex3f(+size / 2.0f, -size / 2.0f, -size / 2.0f);
    glTexCoord3f(1.f, -1.f, 1.f);
    glVertex3f(+size / 2.0f, -size / 2.0f, +size / 2.0f);
    glTexCoord3f(-1.f, -1.f, 1.f);
    glVertex3f(-size / 2.0f, -size / 2.0f, +size / 2.0f);
    glEnd();
}

#endif