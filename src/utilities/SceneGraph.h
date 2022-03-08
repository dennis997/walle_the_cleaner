#ifndef WALL_E_SCENEGRAPH_H
#define WALL_E_SCENEGRAPH_H
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <assimp/Importer.hpp>      // C++ importer interface
#include <assimp/scene.h>           // Output data structure
#include <assimp/postprocess.h>
#include <vector>
#include <iostream>
#include "../api/Mesh.h"
#include "../scenes/surface/Ground.h"
#include "../scenes/surface/Surface.h"
#include "../scenes/robot/Robot.h"
#include "../scenes/sky/Sky.h"
#include "../scenes/surface/TrashCube.h"


// top level nodes
Surface surface;
Robot robot;
Sky sky;

std::vector<Mesh> meshes;

// shapes (nodes)
Ground ground;
TrashCube trashCube;

void processNode(aiNode *node, const aiScene *scene)
{
    // process all the node's meshes (if any)
    for(unsigned int i = 0; i < node->mNumMeshes; i++)
    {
        aiMesh *mesh = scene->mMeshes[node->mMeshes[i]];
        meshes.push_back(Mesh::processMesh(mesh, scene));
    }
    // then do the same for each of its children
    for(unsigned int i = 0; i < node->mNumChildren; i++)
    {
        processNode(node->mChildren[i], scene);
    }
}

/**
 * Add shapes to top level nodes or underneath nodes
 */
void buildSceneGraph() {
    surface.add(&ground);
    surface.add(&trashCube);

    Assimp::Importer importer;
    const aiScene *scene = importer.ReadFile("test.obj",aiProcessPreset_TargetRealtime_Fast);//aiProcessPreset_TargetRealtime_Fast has the configs you'll need

    if( !scene)
    {
        std::cout <<   importer.GetErrorString() << std::endl;
    }
    else{
        std::cout <<   "i am here" << std::endl;
        std::cout <<   "mesh: " << scene->HasMeshes() << std::endl;
        std::cout <<   "materials: " << scene->HasMaterials() << std::endl;
        processNode(scene->mRootNode, scene);
    }


}




/**
 * Prints the three defined top level nodes
 *
 * All added nodes in the buildSceneGraph function will be drawn cascadingly
 */
void printSceneGraph() {
    surface.draw();
    sky.draw();
    robot.draw();
}



#endif //WALL_E_SCENEGRAPH_H
