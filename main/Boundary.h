#ifndef BOUNDARY_H
#define BOUNDARY_H

#include "GameObject.h"

class Boundary : public GameObject {
public:
    Boundary(int posX, int posY, float sizeX, float sizeY);
};

#endif // BOUNDARY_H
