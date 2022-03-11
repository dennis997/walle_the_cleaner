#ifndef WALL_E_GROUND_H
#define WALL_E_GROUND_H

#include <GL/glu.h>
#include "../../model/Scene.h"
#include "../../api/vertex.h"
#include "../../vendor/glut.h"

/**
 * Includes following scenes:
 * - ....
 */
class Ground: public Scene {
private:
    /**
     * Four vertices for a 2d plate
     */
    VERTEX xz, x_z, _xz, _x_z;
    /**
     * Texture ID for mapping groud texture
     */
    GLuint surfaceImage;

    float groundSize;
    float groundHeight;

    /**
     * Actual draw method that draws one object. For this example a 2d plate
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
     * Initial Construction of Groundplate to draw later
     */
    void loadImage();

public:
    Ground();
    std::list<VERTEX> getCoordinates() const;
    float getGroundSize() const;

    /**
     * Access method that is getting called by the renderer
     *
     * @param frameIndex counter from the renderer
     */
    void draw(unsigned int frameIndex) const override;
};


#endif //WALL_E_GROUND_H
