#ifndef WALL_E_BODY_H
#define WALL_E_BODY_H

#include "../../model/Scene.h"

class Body: Scene {
private:
    float size = .4;

public:
    void draw(unsigned int frameIndex) const override;
};


#endif //WALL_E_BODY_H
