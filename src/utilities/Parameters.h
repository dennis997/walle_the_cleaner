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
    int fieldSize = 20;

    // roboter
    glm::vec3 startOrientation = glm::vec3(fieldSize / 2, .0f, 0);
    glm::vec3 startPosition = glm::vec3(fieldSize / 2,0,fieldSize / 2);

    float movementSpeed = 0.005;


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

    int getFieldSize() const {
        return fieldSize;
    }
};

#endif //WALL_E_PARAMETERS_H
