#ifndef WALL_E_COMPONENT
#define WALL_E_COMPONENT

#include "Scene.h"
#include "../vendor/glut.h"

void Scene::drawDebug(const float size) const {
    glPushMatrix();
    {
        glBegin(GL_LINE_STRIP);
        {
            glColor3f(1., 0, 0);
            glVertex3f(0, 0, 0);
            glVertex3f(size, 0, 0);
        }
        glEnd();

        glBegin(GL_LINE_STRIP);
        {
            glColor3f(0, 1., 0);
            glVertex3f(0, 0, 0);
            glVertex3f(0, size, 0);
        }
        glEnd();

        glBegin(GL_LINE_STRIP);
        {
            glColor3f(0, 0, 1.);
            glVertex3f(0, 0, 0);
            glVertex3f(0, 0, size);
        }
        glEnd();

    }
    glPopMatrix();
}

void Scene::draw(const unsigned int frameIndex) const {
    for (const Scene *scene: children) {
        scene->draw(frameIndex);
    }
}

void Scene::add(Scene *component) {
    this->children.push_back(component);
    component->setParent(this);
}

void Scene::setParent(const Scene * parent) {
    this->parent = parent;
}

#endif //WALL_E_COMPONENT

