#ifndef WALL_E_SUN_H
#define WALL_E_SUN_H

#include "../../model/Scene.h"
#include "../../api/vertex.h"


class Sun: public Scene {
private:
    VERTEX position;
    float radius;

    void drawSun() const;
    void drawLight() const;

    void setPosition();


public:
    Sun();

    void draw(unsigned int frameIndex) const override;
};



#endif //WALL_E_SUN_H
