//
// Created by katha on 07.03.22.
//

#ifndef WALL_E_MESH_H
#define WALL_E_MESH_H
#include <GL/glew.h>
#include <string>
#include <vector>
#include "vertex.h"
#include "Texture.h"
#include "Shader.h"
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glx.h>
#include <GL/glext.h>
#include <assimp/scene.h>
#include <iostream>


class Mesh {
public:
    // mesh data
    std::vector<VERTEX> vertices;
    std::vector<unsigned int> indices;
    std::vector<TEXTURE> textures;

    Mesh(std::vector<VERTEX> vertices, std::vector<unsigned int> indices, std::vector<TEXTURE> textures){
        this->vertices = vertices;
        this->indices = indices;
       // this->textures = textures;

        setupMesh();
    };
    static Mesh processMesh(aiMesh *mesh, const aiScene *scene);
    void Draw(Shader &shader);
private:
    //  render data
    unsigned int VAO, VBO, EBO;

    void setupMesh();

    std::vector<TEXTURE> loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName);

};


#endif //WALL_E_MESH_H
