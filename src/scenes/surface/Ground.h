#ifndef WALL_E_GROUND_H
#define WALL_E_GROUND_H

#include <GL/glu.h>
#include "../../model/Scene.h"
#include "../../vendor/glut.h"
#include "glm/vec3.hpp"

/**
 * Includes following scenes:
 * - ....
 */
class Ground: public Scene {
private:
    /**
     * Four vertices for a 2d plate
     */
    glm::vec3 xz, x_z, _xz, _x_z;

    /**
     * Texture ID for mapping ground texture
     */
    GLuint surfaceImage;

    /**
     * Y-Coord for the ground
     */
    float groundHeight;

    /**
     * Number of polygons that are used to execute the ground
     */
    int slices;

    float size;

    /**
     * Actual execute method that draws one object. For this example a 2d plate
     */
    void drawPlate() const;

    /**
     * Calculates all vertex positions
     *
     * @param groundSize of the plate
     * @param groundHeight represents the y value
     */
    void calculate(float groundSize, float groundHeight);

    /**
     * Initial Construction of Groundplate to execute later
     */
    void loadImage();

public:
    Ground();

    /**
     * Access method that is getting called by the renderer
     *
     * @param frameIndex counter from the renderer
     */
    void draw(unsigned int frameIndex) override;
};


#endif //WALL_E_GROUND_H
