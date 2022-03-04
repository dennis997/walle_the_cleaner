#ifndef WALL_E_COMPONENT
#define WALL_E_COMPONENT

#include <GL/glew.h>
#include "Scene.h"

void Scene::printDebug(const float size) const {
    glBegin( GL_LINE_STRIP );
    {
        glColor3f(1.,0,0);
        glVertex3f( 0, 0, 0);
        glVertex3f( size, 0, 0);
    }
    glEnd();

    glBegin( GL_LINE_STRIP );
    {
        glColor3f(0,1.,0);
        glVertex3f( 0, 0, 0);
        glVertex3f( 0, size, 0);
    }
    glEnd();

    glBegin( GL_LINE_STRIP );
    {
        glColor3f(0,0,1.);
        glVertex3f( 0, 0, 0);
        glVertex3f( 0, 0, size);
    }
    glEnd();
}

void Scene::draw() const {
    for (const Scene *c : children) {
        c->draw();
    }
}

void Scene::add(Scene *component) {
    this->children.push_back(component);
}

#endif //WALL_E_COMPONENT

