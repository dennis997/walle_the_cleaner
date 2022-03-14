/* Wuerfel_mit_Normalen.cpp  (inkl. Normalen)                  */
/* Autor: W.-D. Groch                                          */
/* letzte Aenderung:	Groch   02.07.2014                     */
/* ----------------------------------------------------------- */
#include "../GL/freeglut.h"

static void Cube(GLfloat fSeitenL)
{
    glBegin(GL_POLYGON);   //Vorderseite
    glNormal3f(0.0f, 0.0f, 1.0f);
    glColor4f(1.0f,0.0f,0.0f,1.0f);	//ROT = A
    glVertex3f(-fSeitenL/2.0f,-fSeitenL/2.0f,+fSeitenL/2.0f);
    glColor4f(1.0f,1.0f,0.0f,1.0f); //GELB = B
    glVertex3f(+fSeitenL/2.0f,-fSeitenL/2.0f,+fSeitenL/2.0f);
    glColor4f(1.0f,1.0f,1.0f,1.0f); //WEISS = C
    glVertex3f(+fSeitenL/2.0f,+fSeitenL/2.0f,+fSeitenL/2.0f);
    glColor4f(1.0f,0.0f,1.0f,1.0f); //MAGENTA = D
    glVertex3f(-fSeitenL/2.0f,+fSeitenL/2.0f,+fSeitenL/2.0f);
    glEnd();


    glBegin(GL_POLYGON);   //Rechte Seite
    glNormal3f(1.0f, 0.0f, 0.0f);
    glColor4f(1.0f,1.0f,0.0f,1.0f); //GELB = B
    glVertex3f(+fSeitenL/2.0f,-fSeitenL/2.0f,+fSeitenL/2.0f);
    glColor4f(0.0f,1.0f,0.0f,1.0f); //GRUEN
    glVertex3f(+fSeitenL/2.0f,-fSeitenL/2.0f,-fSeitenL/2.0f);
    glColor4f(0.0f,1.0f,1.0f,1.0f);	//CYAN
    glVertex3f(+fSeitenL/2.0f,+fSeitenL/2.0f,-fSeitenL/2.0f);
    glColor4f(1.0f,1.0f,1.0f,1.0f); //WEISS
    glVertex3f(+fSeitenL/2.0f,+fSeitenL/2.0f,+fSeitenL/2.0f);
    glEnd();


    glBegin(GL_POLYGON);   //Rueckseite
    glNormal3f(0.0f, 0.0f, -1.0f);
    glColor4f(0.0f,1.0f,1.0f,1.0f); //CYAN
    glVertex3f(+fSeitenL/2.0f,+fSeitenL/2.0f,-fSeitenL/2.0f);
    glColor4f(0.0f,1.0f,0.0f,1.0f); //GRUEN
    glVertex3f(+fSeitenL/2.0f,-fSeitenL/2.0f,-fSeitenL/2.0f);
    glColor4f(0.0f,0.0f,0.0f,1.0f); //SCHWARZ
    glVertex3f(-fSeitenL/2.0f,-fSeitenL/2.0f,-fSeitenL/2.0f);
    glColor4f(0.0f,0.0f,1.0f,1.0f); //BLAU
    glVertex3f(-fSeitenL/2.0f,+fSeitenL/2.0f,-fSeitenL/2.0f);
    glEnd();


    glBegin(GL_POLYGON);   //Linke Seite
    glNormal3f(-1.0f, 0.0f, 0.0f);
    glColor4f(0.0f,0.0f,1.0f,1.0f); //BLAU
    glVertex3f(-fSeitenL/2.0f,+fSeitenL/2.0f,-fSeitenL/2.0f);
    glColor4f(0.0f,0.0f,0.0f,1.0f); //SCHWARZ
    glVertex3f(-fSeitenL/2.0f,-fSeitenL/2.0f,-fSeitenL/2.0f);
    glColor4f(1.0f,0.0f,0.0f,1.0f); //ROT
    glVertex3f(-fSeitenL/2.0f,-fSeitenL/2.0f,+fSeitenL/2.0f);
    glColor4f(1.0f,0.0f,1.0f,1.0f); //MAGENTA
    glVertex3f(-fSeitenL/2.0f,+fSeitenL/2.0f,+fSeitenL/2.0f);
    glEnd();

    glBegin(GL_POLYGON);   //Deckflaeche
    glNormal3f(0.0f, 1.0f, 0.0f);
    glColor4f(1.0f,0.0f,1.0f,1.0f); //MAGENTA
    glVertex3f(-fSeitenL/2.0f,+fSeitenL/2.0f,+fSeitenL/2.0f);
    glColor4f(1.0f,1.0f,1.0f,1.0f); //WEISS
    glVertex3f(+fSeitenL/2.0f,+fSeitenL/2.0f,+fSeitenL/2.0f);
    glColor4f(0.0f,1.0f,1.0f,1.0f); //CYAN
    glVertex3f(+fSeitenL/2.0f,+fSeitenL/2.0f,-fSeitenL/2.0f);
    glColor4f(0.0f,0.0f,1.0f,1.0f); //BLAU
    glVertex3f(-fSeitenL/2.0f,+fSeitenL/2.0f,-fSeitenL/2.0f);
    glEnd();

    glBegin(GL_POLYGON);   //Bodenflaeche
    glNormal3f(0.0f, -1.0f, 0.0f);
    glColor4f(0.0f,0.0f,0.0f,1.0f); //SCHWARZ
    glVertex3f(-fSeitenL/2.0f,-fSeitenL/2.0f,-fSeitenL/2.0f);
    glColor4f(0.0f,1.0f,0.0f,1.0f); //GRUEN
    glVertex3f(+fSeitenL/2.0f,-fSeitenL/2.0f,-fSeitenL/2.0f);
    glColor4f(1.0f,1.0f,0.0f,1.0f); //GELB
    glVertex3f(+fSeitenL/2.0f,-fSeitenL/2.0f,+fSeitenL/2.0f);
    glColor4f(1.0f,0.0f,0.0f,1.0f); //ROT
    glVertex3f(-fSeitenL/2.0f,-fSeitenL/2.0f,+fSeitenL/2.0f);
    glEnd();

    return;
}