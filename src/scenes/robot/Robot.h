#ifndef WALL_E_ROBOT_H
#define WALL_E_ROBOT_H

#include "../../model/Scene.h"
#include "../../api/orientation.h"
#include "../../utilities/Parameters.h"
#include "../../api/vertex.h"
#include "glm/glm.hpp"
#include "../../utilities/HandlerManager.h"


/**
 * Includes following scenes:
 * - Body
 */
class Robot: public Scene {
private:
    VERTEX position;
    Orientation currentOrientation;

public:
    Robot();

    void draw(unsigned int frameIndex) const override;
    VERTEX getPosition() const;

    void turnUpwards();
    void moveForward();
    void moveBack();
    void moveLeft();
    void moveRight();
};


#endif //WALL_E_ROBOT_H
