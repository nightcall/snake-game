#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Utils.hpp"

#define START_LENGTH    5
#define MAX_LENGTH      100
#define BLOCK_X         20
#define BLOCK_Y         20

enum Direction {
    Right,
    Left,
    Top,
    Down
};

class Snake : public sf::Drawable {
    public:
        Snake();
        ~Snake();
        void update();

    private:
        Direction           myDirection;
        unsigned int        myLength;
        sf::RectangleShape  myBlocks[MAX_LENGTH];

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
#endif // SNAKE_HPP
