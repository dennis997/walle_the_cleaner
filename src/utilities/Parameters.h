#ifndef WALL_E_PARAMETERS_H
#define WALL_E_PARAMETERS_H

#include "../api/orientation.h"
#include "../api/vertex.h"

/**
 * Singleton pattern for a parameter bucket
 */
class Parameter {
private:
    inline static Parameter* instance;

    // roboter
    Orientation startOrientation = Orientation::EAST;
    VERTEX startPosition = VERTEX(1,0,0);

    inline static float movementSpeed = 0.05;

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
    Orientation getStartOrientation() const {
        return startOrientation;
    }

    const VERTEX &getStartPosition() const {
        return startPosition;
    }

    static float getMovementSpeed()  {
        return movementSpeed;
    }
};

#endif //WALL_E_PARAMETERS_H
