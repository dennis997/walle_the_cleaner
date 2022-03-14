#ifndef WALL_E_ROBOT_H
#define WALL_E_ROBOT_H

#include "../../model/Scene.h"
#include "../../api/api.h"
#include "../../utilities/Parameters.h"
#include "glm/glm.hpp"
#include "../../utilities/HandlerManager.h"


/**
 * Includes following scenes:
 */
class Robot: public Scene {
private:
    glm::vec3 position;
    glm::vec3 prevPos;
    glm::vec3 currentOrientation;
    int yAngle;
    bool movedForward;
    bool lightOn;
    float movementSpeed;
    float angleSpeed;

    bool restrictMovement();

public:
    Robot();

    void draw(unsigned int frameIndex) override;

    // movement
    void moveForward();
    void moveBack();
    void moveLeft();
    void moveRight();

    // camera
    void calcViewPoint(int currentDegree);

    // actions
    void toggleLight(Perspective currentPerspective);

    // getter
    const glm::vec3 &getCurrentOrientation() const;
    const bool getLightStatus() const;
    const glm::vec3 &getPosition() const;

};

#endif //WALL_E_ROBOT_H
