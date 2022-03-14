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

Surface::Surface(Robot * robot) {
    this->robot = robot;
}

void Surface::despawnNextTrashCube() {

   calculateDistances();
   std::multimap<float, TrashCube*>::iterator it = trashCubes.begin();

    children.remove(it->second);
    //TODO diplay trash cube
    //robot->displayTrashCube();
    robot->setPickedUpTrashCube(true);
}

void Surface::calculateDistances() {

    glm::vec3 robotPosition = robot->getPosition();
    std::multimap<float, TrashCube*> localTrashCubes;

    for (std::multimap<float, TrashCube*>::iterator it = trashCubes.end(); it != trashCubes.begin(); it--){
        glm::vec3 trashCubePosition = it->second->getPosition();

        float distanceX = trashCubePosition.x - robot->getPosition().x;
        float distanceZ = trashCubePosition.z - robot->getPosition().z;
        float distance = sqrt(pow(2,distanceX) + pow(2,distanceZ));

        localTrashCubes.insert(std::pair<float, TrashCube*>(distance, it->second));
        trashCubes.erase(it);
    }

    for (std::multimap<float, TrashCube*>::iterator it = localTrashCubes.begin(); it != localTrashCubes.end(); it++){
        trashCubes.insert(std::pair<float, TrashCube*>(it->first,it->second));
    }

}

void Surface::layDownTrashCube() {

    TrashCube * trashCube = new TrashCube(robot->getPosition().x,robot->getPosition().y,robot->getPosition().z);
    trashCubes.insert(std::pair<float, TrashCube*>(0, trashCube));
    this->add(trashCube);

    robot->setPickedUpTrashCube(false);

}

void Surface::pickUpOrLayDown() {
    if (robot->isTrashCubePickedUp()){
        despawnNextTrashCube();
    }
    else{
        layDownTrashCube();
    }

}
