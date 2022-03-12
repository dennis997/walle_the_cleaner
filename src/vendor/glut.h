#ifndef WALL_E_GLUT_H
#define WALL_E_GLUT_H

#ifdef __APPLE__
/* Defined before OpenGL and GLUT includes to avoid deprecation messages */
#define GL_SILENCE_DEPRECATION
#include "/usr/local/include/GL/glew.h"
#include <GLUT/glut.h>
#else
#define GL_GLEXT_PROTOTYPES
#include <GL/freeglut.h>
#endif

#endif //WALL_E_GLUT_H
