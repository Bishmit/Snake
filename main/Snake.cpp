#include "Snake.h"

Snake::Snake(float posX, float posY) : GameObject(posX, posY, 10, 10, sf::Color::Green){
    currentDirection = Direction::None;
    nextDirection = Direction::None;
}

void Snake::move() {
    if (isMoving) return;

    sf::Vector2f previousPosition = position;

    if (!isMoving) {
        if (nextDirection != Direction::None &&
            !((currentDirection == Direction::Up && nextDirection == Direction::Down) ||
                (currentDirection == Direction::Down && nextDirection == Direction::Up) ||
                (currentDirection == Direction::Left && nextDirection == Direction::Right) ||
                (currentDirection == Direction::Right && nextDirection == Direction::Left))) {
            currentDirection = nextDirection;
        }

        switch (currentDirection) {
        case Direction::Up: position.y -= 10; break;
        case Direction::Down: position.y += 10; break;
        case Direction::Left: position.x -= 10; break;
        case Direction::Right: position.x += 10; break;
        default: break;
        }
    }

    if (!body.empty()) {
        for (size_t i = body.size() - 1; i > 0; --i) {
            body[i].setPosition(body[i - 1].getPosition());
        }
        body[0].setPosition(previousPosition);
    }
}

void Snake::setDirection(Direction newDirection) {
    nextDirection = newDirection;
}

void Snake::grow() {
    sf::RectangleShape segment;
    segment.setSize(sf::Vector2f(10, 10));
    segment.setFillColor(sf::Color::Yellow);
    segment.setPosition(position);
    body.push_back(segment);
}

void Snake::checkBoundaryCollision() {
    if (position.x < 0 || position.x >= width || position.y < 0 || position.y >= height) {
        isMoving = true;
    }

    for (size_t i = 1; i < body.size(); ++i) {
        if (checkCollision(body[0], body[i])) {
            isMoving = true;
        }
    }
}

bool Snake::hasCollidedWithWall() const {
    return isMoving;
}

void Snake::reset() {
    position = { width / 2, height / 2 };
    shape.setPosition(position);
    body.clear();
    currentDirection = Direction::None;
    nextDirection = Direction::None;
    isMoving = false;
}

void Snake::render(sf::RenderWindow& window) {
    GameObject::render(window);
    for (const auto& segment : body) {
        window.draw(segment);
    }
}
