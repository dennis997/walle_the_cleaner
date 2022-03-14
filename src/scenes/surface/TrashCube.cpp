#include "TrashCube.h"

//#include "../../vendor/glut.h"

void TrashCube::draw(const unsigned int frameIndex) {
    Scene::draw(frameIndex);

    Parameter * parameter = Parameter::getInstance();

    glPushMatrix();
    glTranslatef(position.x,position.y,position.z);
    glColor3f(1,1,1);
    Cube(parameter->getTrashCubeSize());
    glPopMatrix();
}

TrashCube::TrashCube(float x, float y, float z) {
    this->position = glm::vec3(x,y,z);
}

const glm::vec3 &TrashCube::getPosition() const {
    return position;
}

void TrashCube::setPosition(const glm::vec3 &position) {
    TrashCube::position = position;
}
