//
// Created by katha on 07.03.22.
//
#include "Mesh.h"

void Mesh::setupMesh(){

    __glewGenVertexArrays(1, &VAO);
    __glewGenBuffers(1, &VBO);
    __glewGenBuffers(1, &EBO);

    __glewBindVertexArray(VAO);
    __glewBindBuffer(GL_ARRAY_BUFFER, VBO);

    __glewBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(VERTEX), &vertices[0], GL_STATIC_DRAW);

    __glewBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    __glewBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int),
                 &indices[0], GL_STATIC_DRAW);

    // vertex positions
    __glewEnableVertexAttribArray(0);
    __glewVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VERTEX), (void*)0);
    // vertex normals
    __glewEnableVertexAttribArray(1);
    __glewVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(VERTEX), (void*)offsetof(VERTEX, Normal));
    // vertex texture coords
    __glewEnableVertexAttribArray(2);
    __glewVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(VERTEX), (void*)offsetof(VERTEX, TexCoords));

    __glewBindVertexArray(0);

}

Mesh Mesh::processMesh(aiMesh *mesh, const aiScene *scene) {
    std::vector<VERTEX> vertices;
    std::vector<unsigned int> indices;
    std::vector<TEXTURE> textures;

    for(unsigned int i = 0; i < mesh->mNumVertices; i++) {
        VERTEX vertex;
        // process vertex positions, normals and texture coordinates
        glm::vec3 vector;
        vector.x = mesh->mVertices[i].x;
        vector.y = mesh->mVertices[i].y;
        vector.z = mesh->mVertices[i].z;
        vertex.Position = vector;

        vector.x = mesh->mNormals[i].x;
        vector.y = mesh->mNormals[i].y;
        vector.z = mesh->mNormals[i].z;
        vertex.Normal = vector;
/*
        if(mesh->mTextureCoords[0]) // does the mesh contain texture coordinates?
        {
            glm::vec2 vec;
            vec.x = mesh->mTextureCoords[0][i].x;
            vec.y = mesh->mTextureCoords[0][i].y;
            vertex.TexCoords = vec;
        }
        else
            vertex.TexCoords = glm::vec2(0.0f, 0.0f);
*/
        vertices.push_back(vertex);
    }


        // process indices
        for (unsigned int i = 0; i < mesh->mNumFaces; i++) {
            aiFace face = mesh->mFaces[i];
            for (unsigned int j = 0; j < face.mNumIndices; j++)
                indices.push_back(face.mIndices[j]);
        }

    // process material
    /*
    if(mesh->mMaterialIndex >= 0)
    {
        aiMaterial *material = scene->mMaterials[mesh->mMaterialIndex];
        std::vector<TEXTURE> diffuseMaps = loadMaterialTextures(material,
                                                           aiTextureType_DIFFUSE, "texture_diffuse");
        textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());
        std::vector<TEXTURE> specularMaps = loadMaterialTextures(material,
                                                            aiTextureType_SPECULAR, "texture_specular");
        textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
    }
     */

    return Mesh(vertices, indices, textures);
}
/*
std::vector<TEXTURE> Mesh::loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName) {
    std::vector<TEXTURE> textures;
    for(unsigned int i = 0; i < mat->GetTextureCount(type); i++)
    {
        aiString str;
        std::string directory = "../scenes/robot/Robot.h";
        mat->GetTexture(type, i, &str);
        TEXTURE texture;
        texture.id = TextureFromFile(str.C_Str(), directory.c_str());
        texture.type = typeName;
        texture.path = str;
        textures.push_back(texture);
    }
    return textures;

}
 */

#include "Mesh.h"
