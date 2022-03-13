#ifndef WALL_E_FINGER_H
#define WALL_E_FINGER_H

#include "../../model/Scene.h"
#include "glm/vec3.hpp"
#include "../../vendor/Model.h"
#include "../../api/orientation.h"

class Finger: public Scene {
private:
    float size;
    Side orientation;

    glm::vec3 position;

    unsigned int eyeImageId;
    Model model;

    void loadImage();
    void calculate();

public:
    Finger(Side);

    void draw(unsigned int frameIndex) const override;
};


#endif
