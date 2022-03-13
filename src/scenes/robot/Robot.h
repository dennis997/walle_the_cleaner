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
    glm::vec3 prevPos;
    glm::vec3 currentOrientation;
    int yAngle;
    bool movedForward;
    bool lightOn;


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
    void toggleLight(Perspective currentPerspective);

    const glm::vec3 &getCurrentOrientation() const;
    const int getYAngle() const;
    const bool getLightStatus() const;

};

#endif //WALL_E_ROBOT_H
