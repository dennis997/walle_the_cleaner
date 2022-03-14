#ifndef WALL_E_FINGER_H
#define WALL_E_FINGER_H

#include "../../../model/Scene.h"
#include "glm/vec3.hpp"
#include "../../../vendor/Model.h"
#include "../../../api/api.h"
#include "../Robot.h"

class Finger: public Scene {
private:
    glm::vec3 position;
    unsigned int eyeImageId;
    Model model;
    const Robot* robot;


    void loadImage();
    void calculate();
    void initAnimation();


public:
    Finger(const Robot* robot);

    void draw(unsigned int frameIndex) override;
};


#endif
