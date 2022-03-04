#ifndef WALL_E_TRASHCUBE_H
#define WALL_E_TRASHCUBE_H


#include "../../model/Scene.h"
#include "../../api/vertex.h"

/**
 * Includes following scenes:
 * - ....
 */
class TrashCube: public Scene {
private:
public:
    void draw(unsigned int frameIndex) const override;
};

#endif //WALL_E_TRASHCUBE_H
