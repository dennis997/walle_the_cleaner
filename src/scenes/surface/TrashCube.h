#ifndef WALL_E_TRASHCUBE_H
#define WALL_E_TRASHCUBE_H


#include <glm/vec3.hpp>
#include "../../model/Scene.h"
#include "../../vendor/Cube.h"
#include "../../utilities/Parameters.h"
/**
 * Includes following scenes:
 * - ....
 */
class TrashCube: public Scene {
private:
    glm::vec3 position;

public:
  //  TrashCube();
    TrashCube(float x, float y, float z);
    void draw(unsigned int frameIndex) const override;
    const glm::vec3 &getPosition() const;
    void setPosition(const glm::vec3 &position);
};

#endif //WALL_E_TRASHCUBE_H
