/* Wuerfel_mit_Normalen.cpp  (inkl. Normalen)                  */
/* Autor: W.-D. Groch                                          */
/* letzte Aenderung:	Groch   02.07.2014                     */
/* ----------------------------------------------------------- */
#include "../GL/freeglut.h"

static void Cube(GLfloat fSeitenL)
{
    glBegin(GL_POLYGON);   //Vorderseite
    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-fSeitenL/2.0f,-fSeitenL/2.0f,+fSeitenL/2.0f);
    glVertex3f(+fSeitenL/2.0f,-fSeitenL/2.0f,+fSeitenL/2.0f);
    glVertex3f(+fSeitenL/2.0f,+fSeitenL/2.0f,+fSeitenL/2.0f);
    glVertex3f(-fSeitenL/2.0f,+fSeitenL/2.0f,+fSeitenL/2.0f);
    glEnd();


    glBegin(GL_POLYGON);   //Rechte Seite
    glNormal3f(1.0f, 0.0f, 0.0f);
    glVertex3f(+fSeitenL/2.0f,-fSeitenL/2.0f,+fSeitenL/2.0f);
    glVertex3f(+fSeitenL/2.0f,-fSeitenL/2.0f,-fSeitenL/2.0f);
    glVertex3f(+fSeitenL/2.0f,+fSeitenL/2.0f,-fSeitenL/2.0f);
    glVertex3f(+fSeitenL/2.0f,+fSeitenL/2.0f,+fSeitenL/2.0f);
    glEnd();


    glBegin(GL_POLYGON);   //Rueckseite
    glNormal3f(0.0f, 0.0f, -1.0f);
    glVertex3f(+fSeitenL/2.0f,+fSeitenL/2.0f,-fSeitenL/2.0f);
    glVertex3f(+fSeitenL/2.0f,-fSeitenL/2.0f,-fSeitenL/2.0f);
    glVertex3f(-fSeitenL/2.0f,-fSeitenL/2.0f,-fSeitenL/2.0f);
    glVertex3f(-fSeitenL/2.0f,+fSeitenL/2.0f,-fSeitenL/2.0f);
    glEnd();


    glBegin(GL_POLYGON);   //Linke Seite
    glNormal3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(-fSeitenL/2.0f,+fSeitenL/2.0f,-fSeitenL/2.0f);
    glVertex3f(-fSeitenL/2.0f,-fSeitenL/2.0f,-fSeitenL/2.0f);
    glVertex3f(-fSeitenL/2.0f,-fSeitenL/2.0f,+fSeitenL/2.0f);
    glVertex3f(-fSeitenL/2.0f,+fSeitenL/2.0f,+fSeitenL/2.0f);
    glEnd();

    glBegin(GL_POLYGON);   //Deckflaeche
    glNormal3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-fSeitenL/2.0f,+fSeitenL/2.0f,+fSeitenL/2.0f);
    glVertex3f(+fSeitenL/2.0f,+fSeitenL/2.0f,+fSeitenL/2.0f);
    glVertex3f(+fSeitenL/2.0f,+fSeitenL/2.0f,-fSeitenL/2.0f);
    glVertex3f(-fSeitenL/2.0f,+fSeitenL/2.0f,-fSeitenL/2.0f);
    glEnd();

    glBegin(GL_POLYGON);   //Bodenflaeche
    glNormal3f(0.0f, -1.0f, 0.0f);
    glVertex3f(-fSeitenL/2.0f,-fSeitenL/2.0f,-fSeitenL/2.0f);
    glVertex3f(+fSeitenL/2.0f,-fSeitenL/2.0f,-fSeitenL/2.0f);
    glVertex3f(+fSeitenL/2.0f,-fSeitenL/2.0f,+fSeitenL/2.0f);
    glVertex3f(-fSeitenL/2.0f,-fSeitenL/2.0f,+fSeitenL/2.0f);
    glEnd();

    return;
}