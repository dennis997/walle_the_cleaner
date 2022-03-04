#include "utilities/SceneGraph.h"
#include "utilities/Renderer.h"

int main(int argc, char **argv) {
    buildSceneGraph();
    initRenderer(argc, argv);
    return 0;
}