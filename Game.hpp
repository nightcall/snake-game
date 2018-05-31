#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class Game {
    public:
        Game();
        ~Game();
        int launch();

    private:
        sf::RenderWindow myWindow;
};

#endif // GAME_HPP
