#ifndef WALL_E_PARAMETERS_H
#define WALL_E_PARAMETERS_H

#include "../api/orientation.h"
#include "../api/vertex.h"
#include "glm/vec3.hpp"

/**
 * Singleton pattern for a parameter bucket
 */
class Parameter {
private:
    inline static Parameter* instance;
    float fieldSize = 10;

    // roboter
    glm::vec3 startOrientation = glm::vec3(1, .0f, 1);
    glm::vec3 startPosition = glm::vec3(fieldSize / 2,0,fieldSize / 2);

    float movementSpeed = 0.1f;
    float movementAngle = 5.0f;
    int yAngle = 0;
    float radiantApprox = 0.0175f; // 0.0175 = for approx. conversion to radiant (~pi/180)

    float robotSize = 1.f;


public:
    /**
     * Lazy loading singleton instance
     * @return
     */
    static Parameter* getInstance() {
        if (instance == nullptr) {
            instance = new Parameter;
        }

        return instance;
    }

    // getter
    const glm::vec3 &getStartOrientation() const {
        return startOrientation;
    }

    const glm::vec3 &getStartPosition() const {
        return startPosition;
    }

    float getMovementSpeed() const {
        return movementSpeed;
    }

    float getMovementAngle() const {
        return movementAngle;
    }

    float getFieldSize() const {
        return fieldSize;
    }

    int getYAngle() const {
        return yAngle;
    }

    float getRobotSize() const {
        return robotSize;
    }

    float getRadiantApprox() const {
        return radiantApprox;
    }
};

#endif //WALL_E_PARAMETERS_H
