#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "Snake.h"
#include "Food.h"

class Game {
private:
    sf::RenderWindow window;
    std::unique_ptr<Snake> snake;
    std::unique_ptr<Food> food;
    void processEvents();
    void update();
    void render();

public:
    Game();
    void run();
};

#endif // GAME_H
