#ifndef WALL_E_THE_CLEANER_COMPONENT_H
#define WALL_E_THE_CLEANER_COMPONENT_H

#include <list>
#include "../utilities/AnimationExecutor.h"

/**
 * A scene is a node in the scene graph.
 *
 * It can be either a leaf with zero children or a component with n children.
 * Both types are able to draw things to the rendered scene in the execute method.
 *
 * To debug a scene call drawDebug(.5) in your execute method.
 */
class Scene {
private:
    void setParent(const Scene* parent);

protected:
    std::list<Scene *> children;
    const Scene* parent = nullptr;

    AnimationExecutor grabAnimation, idleAnimation;


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
    void drawDebug(float size) const;

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
     *
     * @param frameIndex frame counter incremented by the renderer
     */
    virtual void draw(unsigned int frameIndex);

    void startGrabAnimation(unsigned int frameIndex);

    void startIdleAnimation(unsigned int frameIndex);
};

#endif //WALL_E_THE_CLEANER_COMPONENT_H