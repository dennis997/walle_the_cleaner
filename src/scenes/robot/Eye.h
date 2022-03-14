#ifndef WALL_E_EYE_H
#define WALL_E_EYE_H

#include "../../model/Scene.h"
#include "glm/vec3.hpp"
#include "../../vendor/Model.h"
#include "../../api/api.h"

class Eye: public Scene {
private:
    Side orientation;
    glm::vec3 position;
    unsigned int eyeImageId;
    Model model;

    void loadImage();
    void calculate();

public:
    Eye(Side);

    void draw(unsigned int frameIndex) override;
};


#endif
