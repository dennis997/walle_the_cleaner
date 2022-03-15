#ifndef WALL_E_TRASHCUBE_H
#define WALL_E_TRASHCUBE_H


#include <glm/vec3.hpp>
#include "../../model/Scene.h"
#include "../../vendor/Cube.h"
#include "../../utilities/Parameters.h"
#include "../../vendor/Model.h"

/**
 * Includes following scenes:
 * - ....
 */
class TrashCube: public Scene {
private:
    glm::vec3 position;

    unsigned int imageId;
    void loadImage();
    Model model;

public:
  //  TrashCube();
    TrashCube(float x, float y, float z);
    void draw(unsigned int frameIndex) override;
    const glm::vec3 &getPosition() const;
    void setPosition(const glm::vec3 &position);
};

#endif //WALL_E_TRASHCUBE_H
