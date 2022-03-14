#ifndef WALL_E_CARRIAGE_H
#define WALL_E_CARRIAGE_H

#include "../../model/Scene.h"
#include "glm/vec3.hpp"
#include "../../vendor/Model.h"
#include "../../api/api.h"

class Carriage: public Scene {
private:
    glm::vec3 position;
    unsigned int imageId;
    float trashCubeSize;
    bool visible;

    void loadImage();
    void calculate();
    void initAnimation();

public:
    Carriage();
    void draw(unsigned int frameIndex) override;
};


#endif //WALL_E_CARRIAGE_H
