#include "Surface.h"

Surface::Surface(Robot *robot) {
    this->robot = robot;
}

void Surface::draw(const unsigned int frameIndex) {
    Scene::draw(frameIndex);
}

void Surface::createRandomCubes() {

    Parameter *parameter = Parameter::getInstance();
    int trashCubeBorderX = parameter->getFieldSize() - 1;
    int trashCubeBorderZ = parameter->getFieldSize() - 1;

    for (int i = 0; i < parameter->getNumberOfTrashcubes(); i++) {
        float x = rand() % trashCubeBorderX + 1;
        float z = rand() % trashCubeBorderZ + 1;
        float y = parameter->getTrashCubeSize() / 2;

        TrashCube *trashCube = new TrashCube(x, y, z);

        float distanceX = trashCube->getPosition().x - roundoff(robot->getPosition().x,2);
        float distanceZ = trashCube->getPosition().z - roundoff(robot->getPosition().z,2);
        float distance = roundoff(sqrt(pow(distanceX,2) + pow(distanceZ,2)),2);

        trashCubes.insert(std::pair<float, TrashCube *>(distance, trashCube));
        this->add(trashCube);
    }
}

void Surface::despawnNextTrashCube() {
    calculateDistances();
    std::multimap<float, TrashCube *>::iterator it = trashCubes.begin();
    children.remove(it->second);
    trashCubes.erase(it);
}

void Surface::calculateDistances() {
    glm::vec3 robotPosition = robot->getPosition();
    std::multimap<float, TrashCube *> localTrashCubes;

    for (std::multimap<float, TrashCube*>::iterator it = trashCubes.begin(); it != trashCubes.end(); it++) {

        glm::vec3 trashCubePosition = it->second->getPosition();

        float distanceX = trashCubePosition.x - roundoff(robot->getPosition().x,2);
        float distanceZ = trashCubePosition.z - roundoff(robot->getPosition().z,2);
        float distance = roundoff(sqrt(pow( distanceX,2) + pow(distanceZ,2)),2);

        localTrashCubes.insert(std::pair<float, TrashCube *>(distance, it->second));
    }
    trashCubes.clear();

    for (std::multimap<float, TrashCube *>::iterator it = localTrashCubes.begin(); it != localTrashCubes.end(); it++) {
        trashCubes.insert(std::pair<float, TrashCube *>(it->first, it->second));
    }
}

void Surface::layDownTrashCube() {
    Parameter *parameter = Parameter::getInstance();

    float lookatX = (robot->getPosition().x + robot->getOrientation().x);
    float lookatZ = (robot->getPosition().z + robot->getOrientation().z);

    float trashCubePosX = (robot->getPosition().x + lookatX)/2;
    float trashCubePosZ = (robot->getPosition().z + lookatZ)/2;

    trashCubePosX = (robot->getPosition().x + trashCubePosX)/2;
    trashCubePosZ = (robot->getPosition().z + trashCubePosZ)/2;



    TrashCube *trashCube = new TrashCube(trashCubePosX, parameter->getTrashCubeSize() / 2, trashCubePosZ,robot->getAngle());

    trashCubes.insert(std::pair<float, TrashCube *>(0.0, trashCube));
    this->add(trashCube);
}

void Surface::pickUpOrLayDown() {
    if (robot->hasCube()) {
        layDownTrashCube();
        robot->setHasCube(false);
    } else {
        despawnNextTrashCube();
        robot->setHasCube(true);
    }
}

float Surface::roundoff(float value, unsigned char prec)
{
    float pow_10 = pow(10.0f, (float)prec);
    return round(value * pow_10) / pow_10;
}
