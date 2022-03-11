#ifndef WALL_E_SUN_H
#define WALL_E_SUN_H

#include "../../model/Scene.h"
#include "../../api/vertex.h"


class Sun: public Scene {
private:
    VERTEX position;
    float radius;

    unsigned int sunImageId;

    void drawSun(unsigned int frameIndex) const;
    void drawLight() const;

    void setPosition(int size);

    void loadImage();


public:
    Sun();

    void draw(unsigned int frameIndex) const override;
};



#endif //WALL_E_SUN_H
