#ifndef WALL_E_BODY_H
#define WALL_E_BODY_H

#include "../../model/Scene.h"

class Body: public Scene {
private:
    float size;

public:
    Body();

    void draw(unsigned int frameIndex) const override;
};


#endif //WALL_E_BODY_H
