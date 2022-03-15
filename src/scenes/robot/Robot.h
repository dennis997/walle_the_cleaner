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
    glm::vec3 currentOrientation, stickyOrientation;
    int yAngle, stickyAngle;

    bool movedForward;
    bool lightOn;
    float movementSpeed, angleSpeed;
    bool carryCube;
    AnimationExecutor idleAnimation;
    bool isSticky;
    int lastMovementFrameIndex;
    float idleDuration;

    bool restrictMovement();
    void handleIdle(unsigned int frameIndex);
    void resetIdleTimer();


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
    bool hasCube() const;
    void setHasCube(bool hasCube);
    int getYAngle() const;
    float getAngle();

    const glm::vec3& getOrientation() const;

    void toggleSticky();
};

#endif //WALL_E_ROBOT_H
