#include "Food.h"
#include <cstdlib>

Food::Food(int posX, int posY) : GameObject(posX, posY, 10, 10, sf::Color::White), increaseByfive(false) {
}

void Food::respawn(int score) {
    int newPosX = rand() % static_cast<int>(width - 10);
    int newPosY = rand() % static_cast<int>(height - 10);
    position = sf::Vector2f(newPosX, newPosY);
    shape.setPosition(position);

    if (score % 7 == 0) {
        shape.setFillColor(sf::Color::Cyan);
        shape.setScale(1.5f, 1.5f);
        increaseByfive = true;
    }
    else {
        shape.setFillColor(sf::Color::White);
        shape.setScale(1.f, 1.f);
        increaseByfive = false;
    }
}

bool Food::isBigFood() const {
    return increaseByfive;
}
