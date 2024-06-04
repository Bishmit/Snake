#include "Game.h"

Game::Game() : window(sf::VideoMode(width, height), "Snake"), score(0), fakescore(0) {
    window.setFramerateLimit(20);
    snake = std::make_unique<Snake>(width / 2, height / 2);
    food = std::make_unique<Food>(rand() % static_cast<int>(width - 50), rand() % static_cast<int>(height - 50));

    // setting background picture
    if (!bgtex.loadFromFile("Background/bg.jpg")) {
        std::cout << "Error: BG could not be loaded!" << std::endl;
    }
    bgsprite.setTexture(bgtex);

    // setting font
    if (!font.loadFromFile("Font/PixellettersFull.ttf")) {
        std::cout << "Error: Font could not be loaded!" << std::endl;
    }
    text.setFont(font);
    text.setString("Score: " + std::to_string(this->score));
    text.setCharacterSize(34);
    text.setFillColor(sf::Color::White);
    text.setPosition(650.f, 5.f);
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
        score = 0; 
        fakescore = 0; 
        text.setString("Score: " + std::to_string(this->score));
        snake->reset();
    }

    if (snake->isColliding(*food)) {
        if (food->isBigFood()) {
            score += 5;
        }
        else {
            score++;
        }
        fakescore++; 
        std::cout << score << "\n";
        text.setString("Score: " + std::to_string(this->score));
        text.setCharacterSize(34);
        text.setFillColor(sf::Color::White);
        text.setPosition(650.f, 5.f);

        food->respawn(fakescore);
        snake->grow();
    }
}

void Game::render() {
    window.clear();
    window.draw(bgsprite); 
    snake->render(window);
    food->render(window);
    window.draw(text);
    window.display();
}

void Game::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}
