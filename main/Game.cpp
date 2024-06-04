#include "Game.h"

Game::Game() : window(sf::VideoMode(width, height), "Snake") {
    window.setFramerateLimit(10);
    snake = std::make_unique<Snake>(width / 2, height / 2);
    food = std::make_unique<Food>(rand() % static_cast<int>(width - 50), rand() % static_cast<int>(height - 50));
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) window.close();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            snake->setDirection(Direction::Up);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            snake->setDirection(Direction::Down);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            snake->setDirection(Direction::Left);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            snake->setDirection(Direction::Right);
        }
    }
}

void Game::update() {
    snake->move();
    snake->checkBoundaryCollision();

    if (snake->hasCollidedWithWall()) {
        // Reset the snake to start from the middle
        snake->reset();
    }

    if (snake->isColliding(*food)) {
        food->respawn();
        snake->grow();
    }
}

void Game::render() {
    window.clear();

    snake->render(window);
    food->render(window);

    window.display();
}

void Game::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}
