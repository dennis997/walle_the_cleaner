#ifndef WALL_E_NECK_H
#define WALL_E_NECK_H

#include "../../model/Scene.h"
#include "glm/vec3.hpp"
#include "../../vendor/Model.h"

class Neck: public Scene {
private:
    Model model;
    glm::vec3 position;

    unsigned int neckImageId;

    void loadImage();
    void calculate();

public:
    Neck();
    void draw(unsigned int frameIndex) override;
};


#endif //WALL_E_NECK_H
