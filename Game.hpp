#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Snake.hpp"

class Game {
    public:
        Game();
        ~Game();
        int launch();

    private:
        sf::RenderWindow    myWindow;
        Snake               mySnake;
};

#endif // GAME_HPP
