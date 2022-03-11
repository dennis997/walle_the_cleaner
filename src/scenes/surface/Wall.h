#ifndef WALL_E_WALL_H
#define WALL_E_WALL_H

#include "../../model/Scene.h"
#include <glm/glm.hpp>

enum WallSide {
    LEFT, RIGHT, TOP, DOWN
};

class Wall: public Scene {
private:
    glm::vec3 xz, _xz, x_z, _x_z;

    void calculate(WallSide wallSide, int fieldSize);

public:
    Wall(WallSide wallSide);


    void draw(unsigned int frameIndex) const override;


};


#endif //WALL_E_WALL_H
