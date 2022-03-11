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

    // roboter
    glm::vec3 startOrientation = glm::vec3(.15f, .0f, .0f);
    glm::vec3 startPosition = glm::vec3(1,0,0);

    float movementSpeed = 0.05;

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
};

#endif //WALL_E_PARAMETERS_H
