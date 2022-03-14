#ifndef WALL_E_CARRIAGE_H
#define WALL_E_CARRIAGE_H

#include "../../model/Scene.h"
#include "glm/vec3.hpp"
#include "../../vendor/Model.h"
#include "../../api/api.h"
#include "../surface/Surface.h"

class Carriage: public Scene {
private:
    glm::vec3 position;
    unsigned int imageId;
    float trashCubeSize;
    bool visible;
    Robot* robot;
    Surface* surface;

    void loadImage();
    void calculate();
    void initAnimation();

    void callback();

public:
    Carriage(Robot* robot, Surface* surface);
    void draw(unsigned int frameIndex) override;
};


#endif //WALL_E_CARRIAGE_H
