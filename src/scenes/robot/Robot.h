#ifndef WALL_E_ROBOT_H
#define WALL_E_ROBOT_H

#include "../../model/Scene.h"
#include "../../api/position.h"
#include "../../utilities/Parameters.h"

/**
 * Includes following scenes:
 * - Body
 */
class Robot: public Scene {
private:
    Position position;
    Orientation currentOrientation;

public:
    Robot();

    void draw(unsigned int frameIndex) const override;

    void turnUpwards();
};


#endif //WALL_E_ROBOT_H
