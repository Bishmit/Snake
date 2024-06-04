#ifndef FOOD_H
#define FOOD_H

#include "GameObject.h"
#include"global.h"

class Food : public GameObject {
public:
    Food(int posX, int posY);
    void respawn();
};

#endif // FOOD_H
