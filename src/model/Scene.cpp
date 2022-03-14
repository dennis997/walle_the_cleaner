#ifndef WALL_E_COMPONENT
#define WALL_E_COMPONENT

#include "Scene.h"
#include "../vendor/glut.h"

/**
 * Red      -> X-Axis
 * Blue     -> Z-Axis
 * Green    -> Y-Axis
 */
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

void Scene::draw(const unsigned int frameIndex) {
    grabAnimation.animate(frameIndex);
    idleAnimation.animate(frameIndex);

    for (Scene *scene: children) {
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

void Scene::startGrabAnimation(const unsigned int frameIndex) {
    grabAnimation.start(frameIndex);
    for (Scene *scene: children) {
        scene->startGrabAnimation(frameIndex);
    }
}

void Scene::startIdleAnimation(unsigned int frameIndex) {
    idleAnimation.start(frameIndex);
    for (Scene *scene: children) {
        scene->startIdleAnimation(frameIndex);
    }
}


#endif //WALL_E_COMPONENT

