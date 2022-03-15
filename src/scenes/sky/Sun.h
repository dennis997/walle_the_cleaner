#ifndef WALL_E_SUN_H
#define WALL_E_SUN_H

#include "../../model/Scene.h"
#include "glm/vec3.hpp"


class Sun: public Scene {
private:
    glm::vec3 position;
    float radius;
    float fieldSize;

    void drawSun(unsigned int frameIndex) const;
    void calculate();

    unsigned int sunImageId;
    void loadImage();

public:
    Sun();

    void draw(unsigned int frameIndex) override;
};



#endif //WALL_E_SUN_H
