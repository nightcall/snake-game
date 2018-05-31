#include "Snake.hpp"

Snake::Snake() :
myDirection (Left),
myLength    (START_LENGTH) {
    for(unsigned int i(0); i < MAX_LENGTH; ++i) {
        myBlocks[i].setSize(sf::Vector2f(BLOCK_X, BLOCK_Y));
        myBlocks[i].setFillColor(sf::Color(random(0, 255), random(0, 255), random(0, 255)));
        myBlocks[i].setPosition(sf::Vector2f(i * BLOCK_X, i * BLOCK_Y));
    }

    // Intialize first 5
    for(unsigned int i(0); i < START_LENGTH; ++i) {
        myBlocks[i].setPosition(400 + (i * BLOCK_X), 300);
    }
}

Snake::~Snake() {

}

void Snake::update() {
    sf::Vector2f nextHeadPosition = myBlocks[0].getPosition();

    switch(myDirection) {
        case Left:
            nextHeadPosition.x -= BLOCK_X;
            break;

        case Right:
            nextHeadPosition.x += BLOCK_X;
            break;

        case Top:
            nextHeadPosition.y -= BLOCK_Y;
            break;

        case Down:
            nextHeadPosition.y += BLOCK_Y;
            break;
    }

    for(unsigned int i(myLength - 1); i > 0; --i) {
        myBlocks[i].setPosition(myBlocks[i - 1].getPosition());
    }

    myBlocks[0].setPosition(nextHeadPosition);
}

void Snake::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for(unsigned int i(0); i < myLength; ++i) {
        target.draw(myBlocks[i]);
    }
}
