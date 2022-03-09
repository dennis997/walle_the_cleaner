#ifndef WALL_E_RENDERER_H
#define WALL_E_RENDERER_H

#include "../vendor/glut.h"
#include <iostream>
#include <chrono>
#include "../events/KeyInput.h"
#include "SceneGraph.h"
#include "HandlerManager.h"
#include "../vendor/SOIL.h"

int waitDuration = 10; // in milliseconds
GLuint tex_2d;


/**
 * Callback every frame for the scene graph components
 */
void animate(int frameIndex) {
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    glClear(GL_COLOR_BUFFER_BIT);
    invokeHandlers(frameIndex);

    printSceneGraph(frameIndex);

    glutPostRedisplay();
    glutTimerFunc(waitDuration, animate, ++frameIndex);

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Frametime: " << std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count() << "[ms]" << std::endl;
}

/**
 * Callback every frame for display parameters
 */
void renderScene() {
    glLoadIdentity();
    glClear( GL_DEPTH_BUFFER_BIT);


    glutSwapBuffers();
}

/**
 * Callback on window resize
 */
void reshape(int width, int height) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, width, height);
    gluPerspective(45., 1, 0.1, 20.);
    glMatrixMode(GL_MODELVIEW);
}

/**
 * Init render configurations
 */
void initRenderer(int argc, char** argv) {
    #ifdef __APPLE__
    #else
       // glewInit();
    #endif
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800,800);
    glutCreateWindow("Wall-E");
    glutDisplayFunc(renderScene);
    glutReshapeFunc(reshape);
    glutTimerFunc(waitDuration,animate,0);
    glutKeyboardFunc(keyInputListener);


    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_DEPTH_TEST);
}

void startRendering() {
    glutMainLoop();
}

#endif //WALL_E_RENDERER_H
