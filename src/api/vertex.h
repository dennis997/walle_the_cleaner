#ifndef WALL_E_VERTEX_H
#define WALL_E_VERTEX_H

/**
 * Represents a Vertex with a x, y, z value
 */
struct VERTEX {
    float x, y, z;

    VERTEX(): x(0), y(0), z(0) {}
    VERTEX(float x, float y, float z) : x(x), y(y), z(z) {}
};

#endif //WALL_E_VERTEX_H
