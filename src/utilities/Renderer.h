#ifndef WALL_E_RENDERER_H
#define WALL_E_RENDERER_H

#include "../vendor/glut.h"
#include <iostream>
#include <chrono>
#include "../events/KeyInput.h"
#include "SceneGraph.h"
#include "HandlerManager.h"
#include "../vendor/SOIL.h"
#include "Parameters.h"

int waitDuration = 10; // in milliseconds

HandlerManager* _handlerManager = nullptr;

/**
 * Callback every frame for the scene graph components
 */
void animate(int frameIndex) {
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    _handlerManager->invokeHandlers(frameIndex);

    printSceneGraph(frameIndex);

    glutPostRedisplay();
    glutTimerFunc(waitDuration, animate, ++frameIndex);

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    //std::cout << "Frametime: " << std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count() << "[ms]" << std::endl;
}

/**
 * Callback every frame for display parameters
 */
void renderScene() {
    glLoadIdentity();
    glClear( GL_DEPTH_BUFFER_BIT);
    glutSwapBuffers();

    unsigned int vertex_buffer;
}

/**
 * Callback on window resize
 */
void reshape(int width, int height) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, width, height);
    gluPerspective(60., 1, 0.1, 20.);
    glMatrixMode(GL_MODELVIEW);
}


void initLight_0() {
    Parameter* parameters = Parameter::getInstance();
    float fieldSize = parameters->getFieldSize();

    GLfloat light_position[] = {fieldSize / 2.f, 2.f, fieldSize / 2.f,0.f};
    GLfloat light_ambient[] = { .5f, .4f, .25f, 1.f }; // intensity of light
    GLfloat light_diffuse[] = { 0.60f, .5f, 0.f, 1.f }; // color of light

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 1.f);
    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, .0f);
    glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.f);

    glEnable(GL_LIGHT0);
}

void initLight_1() {
    Parameter* parameters = Parameter::getInstance();

    GLfloat light_position[] = {0.f, .1f, -.2f,1.f};

    GLfloat light_direction[] = { 0.f, -.25f, -1.f};
    GLfloat light_ambient[] = { .5f, .5f, .5f, 1.f }; // intensity of light
    GLfloat light_diffuse[] = { 0.952f, 0.843f, 0.207f, 1.f }; // color of light
    GLfloat light_specular[] = { 1.f, 1.f, 1.f, 1.f };

    glLightfv(GL_LIGHT1, GL_POSITION, light_position);
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, light_direction);
    glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular);
    glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 1.f);
    glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.1f);
    glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.3f);
    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 20.f);
    glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 10.f);

    //glEnable(GL_LIGHT1);
}

void initLight_2() {
    Parameter* parameters = Parameter::getInstance();

    GLfloat light_position[] = {0.f, 1.8f, -.2f, 1.f};  // 1.8 = camera distance to robot + 0.1

    GLfloat light_direction[] = { 0.f, -.25f, -1.f};
    GLfloat light_ambient[] = { 1.f, 1.f, 1.f, 1.f }; // intensity of light
    GLfloat light_diffuse[] = { 0.952f, 0.843f, 0.207f, 1.f }; // color of light
    GLfloat light_specular[] = { 1.f, 1.f, 1.f, 1.f };

    glLightfv(GL_LIGHT2, GL_POSITION, light_position);
    glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, light_direction);
    glLightfv(GL_LIGHT2, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT2, GL_SPECULAR, light_specular);
    glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION, 1.f);
    glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION, 0.1f);
    glLightf(GL_LIGHT2, GL_QUADRATIC_ATTENUATION, 0.3f);
    glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 20.f);
    glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 10.f);

    //glEnable(GL_LIGHT2);
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
    glutKeyboardFunc([](unsigned char key, int x, int y) {
        keyInputListener(key, x, y, _handlerManager);
    });


    glShadeModel(GL_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glLightModelf(GL_LIGHT_MODEL_COLOR_CONTROL,GL_SEPARATE_SPECULAR_COLOR);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    initLight_0();
    initLight_1();
    initLight_2();
    glColorMaterial ( GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE ) ;
    glEnable(GL_DEPTH_TEST);
    glClearDepth(1.0);
    glEnable(GL_NORMALIZE);
}



void setHandlerManager(HandlerManager* handlerManager) {
    _handlerManager = handlerManager;
}

void startRendering() {
    if (_handlerManager == nullptr) {
        std::cerr << "You have to initialize the handler manager first" << std::endl;
        return;
    }

    glutMainLoop();
}

#endif //WALL_E_RENDERER_H
