#include "Food.h"
#include <cstdlib>

Food::Food(int posX, int posY) : GameObject(posX, posY, 10, 10, sf::Color::White) {
}

void Food::respawn() {
    int newPosX = rand() % static_cast<int>(width - 10);
    int newPosY = rand() % static_cast<int>(height - 10);
    position = sf::Vector2f(newPosX, newPosY);
    shape.setPosition(position);
}
