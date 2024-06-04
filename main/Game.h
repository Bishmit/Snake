#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "Snake.h"
#include "Food.h"
#include"GameObject.h"

class Game {
private:
    int score, fakescore;
    sf::Texture bgtex; 
    sf::Sprite bgsprite; 
    sf::Text text;
    sf::Font font;
    sf::RenderWindow window;
    std::unique_ptr<Snake> snake;
    std::unique_ptr<Food> food;
    void processEvents();
    void update();
    void render(); 
    GameObject g_obj; 

public:
    Game();
    void run();
};

#endif // GAME_H
