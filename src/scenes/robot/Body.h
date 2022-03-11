#ifndef WALL_E_BODY_H
#define WALL_E_BODY_H

#include "../../model/Scene.h"

class Body: public Scene {
private:
    float size = .1;

public:
    void draw(unsigned int frameIndex) const override;

    float getSize() const;
};


#endif //WALL_E_BODY_H
