#ifndef FOOD_H
#define FOOD_H

#include "GameObject.h"
#include"global.h"

class Food : public GameObject {
    bool increaseByfive; 
public:
    Food(int posX, int posY);
    void respawn(int score);
    bool isBigFood() const;
};

#endif // FOOD_H
