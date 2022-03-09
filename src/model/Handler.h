#ifndef WALL_E_HANDLER_H
#define WALL_E_HANDLER_H

#include <list>

class Handler {
public:
    virtual ~Handler() = default;
    virtual void executeStep(unsigned int frameIndex) = 0;
};

#endif //WALL_E_HANDLER_H
