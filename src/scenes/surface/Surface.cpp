#include "Surface.h"

void Surface::draw(const unsigned int frameIndex) const {
    Scene::draw(frameIndex);
}

void Surface::createRandomCubes() {

    Parameter * parameter = Parameter::getInstance();
    int trashCubeBorderX = parameter->getFieldSize() - 1;
    int trashCubeBorderZ = parameter->getFieldSize() - 1;

    for (int i = 0; i < parameter->getNumberOfTrashcubes(); i++){
        float x = rand() % trashCubeBorderX + 1;
        float z = rand() % trashCubeBorderZ + 1;
        float y = parameter->getTrashCubeSize() / 2;

        TrashCube * trashCube = new TrashCube(x,y,z);

        float distanceX = trashCube->getPosition().x - robot->getPosition().x;
        float distanceZ = trashCube->getPosition().z - robot->getPosition().z;
        float distance = sqrt(pow(2,distanceX) + pow(2,distanceZ));

        trashCubes.insert(std::pair<float, TrashCube*>(distance, trashCube));
        this->add(trashCube);

    }
}

Surface::Surface(Robot robot) {
    this->robot = &robot;
}
