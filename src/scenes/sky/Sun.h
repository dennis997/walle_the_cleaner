#ifndef WALL_E_SUN_H
#define WALL_E_SUN_H

#include "../../model/Scene.h"
#include "glm/vec3.hpp"


class Sun: public Scene {
private:
    glm::vec3 position;
    float radius;

    void drawSun(unsigned int frameIndex) const;
    void calculate(int size);

    unsigned int sunImageId;
    void loadImage();

public:
    Sun();

    void draw(unsigned int frameIndex) const override;
};



#endif //WALL_E_SUN_H
