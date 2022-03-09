#include "utilities/SceneGraph.h"
#include "utilities/Renderer.h"

int main(int argc, char **argv) {
    initRenderer(argc, argv);
    buildSceneGraph();

    startRendering();

    return 0;
}