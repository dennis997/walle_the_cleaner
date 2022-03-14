#include "utilities/SceneGraph.h"
#include "utilities/Renderer.h"

int main(int argc, char **argv) {
    initRenderer(argc, argv);
    buildSceneGraph();

    auto* handlerManager = new HandlerManager();
    setHandlerManager(handlerManager);

    startRendering();

    return 0;
}