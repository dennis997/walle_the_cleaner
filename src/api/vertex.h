#ifndef WALL_E_VERTEX_H
#define WALL_E_VERTEX_H

#include <glm/glm.hpp>
/**
 * Represents a Vertex with a x, y, z value
 */
struct VERTEX {

    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;

    VERTEX(){
        this->Position.x = 0;
        this->Position.y = 0;
        this->Position.z = 0;
    }
    VERTEX(float x, float y, float z) {
        this->Position.x = x;
        this->Position.y = y;
        this->Position.z = z;
    }
};

#endif //WALL_E_VERTEX_H
