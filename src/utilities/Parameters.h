#ifndef WALL_E_PARAMETERS_H
#define WALL_E_PARAMETERS_H

#include "../api/position.h"

/**
 * Singleton pattern for a parameter bucket
 */
class Parameter {
private:
    inline static Parameter* instance;

    // roboter
    Orientation startOrientation = Orientation::EAST;
    Position startPosition = Position(1,1,0);

    int movementSpeed = 5; // in pixel

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

    const Position &getStartPosition() const {
        return startPosition;
    }

    int getMovementSpeed() const {
        return movementSpeed;
    }
};

#endif //WALL_E_PARAMETERS_H
