#include "Wall.h"

#include "../../utilities/Parameters.h"

Wall::Wall(const WallSide wallSide) {
    Parameter* parameters = Parameter::getInstance();

    calculate(wallSide, parameters.getFi);
}

void Wall::calculate(const WallSide wallSide, const ) {
    // ground level
    xz.y = 0;
    _xz.y = 0;
    x_z.y = 0;
    _x_z.y = 0;


    switch (wallSide) {
        case LEFT:
            xz.x =
    }
}
