#ifndef SNAKE_H
#define SNAKE_H

#include "GameObject.h"
#include <vector>
#include"global.h"

enum class Direction { None, Up, Down, Left, Right };

class Snake : public GameObject {
    Direction currentDirection;
    Direction nextDirection;
    std::vector<sf::RectangleShape> body;

public:
    Snake(float posX, float posY);
    void move();
    void setDirection(Direction newDirection);
    void grow();
    void checkBoundaryCollision();
    bool hasCollidedWithWall() const;
    void reset();
    void render(sf::RenderWindow& window) override;
};

#endif // SNAKE_H
