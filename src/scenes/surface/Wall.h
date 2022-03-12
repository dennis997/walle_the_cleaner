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
    glm::vec3 vertex_normal;
    GLuint img_id;

    void calculate(WallSide wallSide, float size);
    void loadImage(WallSide wallSide);

public:
    Wall(WallSide wallSide);


    void draw(unsigned int frameIndex) const override;
};


#endif //WALL_E_WALL_H
