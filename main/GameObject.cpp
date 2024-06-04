#include "GameObject.h"

GameObject::GameObject(float posX, float posY, float sizeX, float sizeY, sf::Color color) {
    position.x = posX;
    position.y = posY;
    shape.setPosition(position);
    shape.setSize(sf::Vector2f(sizeX, sizeY));
    shape.setFillColor(color);
}

void GameObject::render(sf::RenderWindow& window) {
    shape.setPosition(position);
    window.draw(shape);    
}

bool GameObject::isColliding(const GameObject& other) const {
    return shape.getGlobalBounds().intersects(other.shape.getGlobalBounds());
}

bool GameObject::checkCollision(const sf::RectangleShape& a, const sf::RectangleShape& b) const {
    return a.getGlobalBounds().intersects(b.getGlobalBounds());
}

void GameObject::resetPosition(float posX, float posY) {
    position.x = posX;
    position.y = posY;
    shape.setPosition(position);
}
