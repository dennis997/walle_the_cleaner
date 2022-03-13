#ifndef WALL_E_NECK_H
#define WALL_E_NECK_H

#include "../../model/Scene.h"
#include "glm/vec3.hpp"
#include "../../vendor/Model.h"

class Neck: public Scene {
private:
    float size;

    glm::vec3 position;

    unsigned int neckImageId;
    Model model;
    void loadImage();

public:
    Neck();

    void draw(unsigned int frameIndex) const override;
};


#endif //WALL_E_NECK_H
