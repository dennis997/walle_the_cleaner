#ifndef WALL_E_THE_CLEANER_COMPONENT_H
#define WALL_E_THE_CLEANER_COMPONENT_H

#include <list>
#ifdef __APPLE__
/* Defined before OpenGL and GLUT includes to avoid deprecation messages */
#define GL_SILENCE_DEPRECATION
#include "/usr/local/include/GL/glew.h"
#else
#include <GL/freeglut.h>
#endif


/**
 * A scene is a node in the scene graph.
 *
 * It can be either a leaf with zero children or a component with n children.
 * Both types are able to draw things to the rendered scene in the draw method.
 *
 * To debug a scene call printDebug(.5) in your draw method.
 */
class Scene {
protected:
    std::list<Scene *> children;

    /**
     * Draws a debug coordinate system
     * red = x
     * green = y
     * blue = z
     *
     * It will be printed to the local coordinate system
     *
     * @param size length of the coord lines
     */
    void printDebug(float size) const;

public:
    virtual ~Scene() = default;

    /**
     * Adds child nodes to the current scene node
     * @param component
     */
    void add(Scene *component);

    /**
     * This method is getting called by the renderer
     *
     * All child nodes will be drawn by a cascaded depth first invocation
     */
    virtual void draw() const;
};

#endif //WALL_E_THE_CLEANER_COMPONENT_H