#ifndef WALL_E_POSITION_H
#define WALL_E_POSITION_H

enum class Orientation {
    NORTH, SOUTH, EAST, WEST
};

struct Position {
    int x, y, z;

    Position() = default;
    Position(int x, int y, int z): x(x), y(y), z(z) {};
};

#endif //WALL_E_POSITION_H
