#ifndef WALL_E_RENDERER_H
#define WALL_E_RENDERER_H

#include "../vendor/glut.h"
#include <iostream>
#include <chrono>
#include "../events/KeyInput.h"
#include "SceneGraph.h"

int waitDuration = 10; // in milliseconds

/**
 * Callback every frame for the scene graph components
 */
void animate(int value) {
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    printSceneGraph(value);

    glutPostRedisplay();
    glutTimerFunc(waitDuration, animate, ++value);

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "glut: " << glutGet(GLUT_ELAPSED_TIME) / value << std::endl;
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count() << "[ms]" << std::endl;
}

/**
 * Callback every frame for display parameters
 */
void renderScene() {
    glLoadIdentity ();
    glClear( GL_DEPTH_BUFFER_BIT);
    gluLookAt(3, 2, 1, 0, 0, 0, 0, 1, 0);

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



    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glutMainLoop();
}

#endif //WALL_E_RENDERER_H
