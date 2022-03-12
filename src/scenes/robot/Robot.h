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
w */
class Robot: public Scene {
private:
    glm::vec3 position;
    glm::vec3 currentOrientation;
    int yAngle;
    bool movedForward;

public:
    Robot();

    void draw(unsigned int frameIndex) const override;
    const glm::vec3 &getPosition() const;

    void moveForward();
    void moveBack();
    void moveLeft();
    void moveRight();
    void calcViewPoint(int currentDegree);
    bool restrictMovement();
    bool checkPointOnLine(std::pair<glm::vec3, glm::vec3>, glm::vec3);

    const glm::vec3 &getCurrentOrientation() const;
};

//    dxc = currPoint.x - point1.x;
//    dyc = currPoint.y - point1.y;
//
//    dxl = point2.x - point1.x;
//    dyl = point2.y - point1.y;
//
//    cross = dxc * dyl - dyc * dxl;
//
//    vif (cross != 0)
//    return false;


#endif //WALL_E_ROBOT_H
