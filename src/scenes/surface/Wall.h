#ifndef WALL_E_WALL_H
#define WALL_E_WALL_H

#include "../../model/Scene.h"
#include <glm/glm.hpp>
#include <vector>
#include <GL/gl.h>
#include "GL/glext.h"

enum WallSide {
    LEFT, RIGHT, BACK, FRONT
};

class Wall: public Scene {
private:
    std::vector<float> vertices;
    GLuint img_id;

    void calculate(WallSide wallSide, float fieldSize);
    void loadImage(WallSide wallSide);

public:
    Wall(WallSide wallSide);


    void draw(unsigned int frameIndex) const override;
};


#endif //WALL_E_WALL_H
