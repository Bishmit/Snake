#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>

class GameObject {
protected:
    sf::Vector2f position;
    sf::RectangleShape shape;
    bool isMoving = false;

public:
    GameObject(float posX, float posY, float sizeX, float sizeY, sf::Color color);
    virtual void render(sf::RenderWindow& window);
    virtual bool isColliding(const GameObject& other) const;
    bool checkCollision(const sf::RectangleShape& a, const sf::RectangleShape& b) const;
    virtual void resetPosition(float posX, float posY);
};

#endif // GAMEOBJECT_H
