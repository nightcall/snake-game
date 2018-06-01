#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Snake.hpp"

class Game {
    public:
        Game();
        ~Game();
        int launch();

    private:
        sf::RenderWindow    myWindow;
        Snake               mySnake;
        sf::Font            myFont;
        sf::Text            myPointsText;
        sf::Text            myGameOverText;
        sf::Text            myPressEnterText;

        bool initialize();
};

#endif // GAME_HPP
