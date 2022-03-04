#ifndef WALL_E_PARAMETERS_H
#define WALL_E_PARAMETERS_H

#include "../api/position.h"

/**
 * Singleton pattern for a parameter bucket
 */
class Parameter {
private:
    static Parameter* instance;

    Orientation startOrientation = Orientation::EAST;
    Position startPosition = Position(1,1,0);

    int moveSpeed = 5; // pixel per frame -> //TODO: not the best solution bc the frame rate can change dynamically

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

    int getMoveSpeed() const {
        return moveSpeed;
    }
};

#endif //WALL_E_PARAMETERS_H
