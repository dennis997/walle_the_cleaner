#ifndef WALL_E_WHEEL_H
#define WALL_E_WHEEL_H

#include "../../model/Scene.h"
#include <glm/glm.hpp>

#include "../../vendor/Model.h"
#include "../../api/orientation.h"

class Wheel: public Scene {
private:
    glm::vec3 position;
    Side orientation;
    Model model;
    unsigned int wheelImgId;


    void calculate();
    void loadImage();

public:
    Wheel(Side orientation);

    void draw(unsigned int frameIndex) const override;
};


#endif //WALL_E_WHEEL_H
