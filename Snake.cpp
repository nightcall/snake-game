#include "Snake.hpp"

Snake::Snake() {
    initialize();
}

Snake::~Snake() {

}

unsigned int Snake::points() const {
    return myPoints;
}

void Snake::initialize() {
    myPoints = 0;
    myIsGameOver = false;
    myDirection = Left;
    myNextDirection = Left;
    myLength = START_LENGTH;

    // Initialize colors of snake
    for(unsigned int i(0); i < MAX_LENGTH; ++i) {
        myBlocks[i].setSize(sf::Vector2f(BLOCK_X, BLOCK_Y));
        myBlocks[i].setFillColor(sf::Color(random(0, 255), random(0, 255), random(0, 255)));
        myBlocks[i].setPosition(sf::Vector2f(i * BLOCK_X, i * BLOCK_Y));
    }

    // Intialize first 5 blocks position
    for(unsigned int i(0); i < START_LENGTH; ++i) {
        myBlocks[i].setPosition((WIN_X / 2) + (i * BLOCK_X), (WIN_Y / 2));
    }

    // Intialize first meat pos & color
    myMeat.setSize(sf::Vector2f(BLOCK_X, BLOCK_Y));
    generateNextMeat();
}

bool Snake::isBlockInSnake(sf::Vector2f position) const {
    for(unsigned int i(0); i < myLength; ++i) {
        if(position == myBlocks[i].getPosition())
            return true;
    }

    return false;
}

void Snake::generateNextMeat() {
    sf::Vector2f nextMeatPosition;

    do {
        nextMeatPosition.x = random(0, NUM_BLOCKS_X - 1) * BLOCK_X;
        nextMeatPosition.y = random(0, NUM_BLOCKS_Y - 1) * BLOCK_Y;
    } while(isBlockInSnake(nextMeatPosition));

    myMeat.setPosition(nextMeatPosition);
    myMeat.setFillColor(sf::Color(random(0, 255), random(0, 255), random(0, 255)));
}

void Snake::update() {
    myDirection = myNextDirection;
    sf::Vector2f nextHeadPosition = myBlocks[0].getPosition();

    switch(myDirection) {
        case Left:
            nextHeadPosition.x -= BLOCK_X;
            break;

        case Right:
            nextHeadPosition.x += BLOCK_X;
            break;

        case Up:
            nextHeadPosition.y -= BLOCK_Y;
            break;

        case Down:
            nextHeadPosition.y += BLOCK_Y;
            break;
    }

    // Test if next head position is inside the snake e.g. has it eaten itself
    if(isBlockInSnake(nextHeadPosition)) {
        myIsGameOver = true;
        return;
    }

    // Test if next head position is outside the box
    if(nextHeadPosition.x < 0
    || nextHeadPosition.x >= WIN_X
    || nextHeadPosition.y < 0
    || nextHeadPosition.y >= WIN_Y) {
        myIsGameOver = true;
        return;
    }

    // Shift snake to move it
    for(unsigned int i(myLength - 1); i > 0; --i) {
        myBlocks[i].setPosition(myBlocks[i - 1].getPosition());
    }

    myBlocks[0].setPosition(nextHeadPosition);

    // Test if head of the snake has eaten a meat
    if(nextHeadPosition == myMeat.getPosition()) {

        // Test if snake can get any longer
        if(myLength + 1 < MAX_LENGTH) {
            myBlocks[myLength].setPosition(myBlocks[myLength - 1].getPosition());
            myBlocks[myLength].setFillColor(myMeat.getFillColor());
            ++myLength;
            myPoints += 5;
        }

        generateNextMeat();
    }
}

void Snake::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    // Draw snake
    for(unsigned int i(0); i < myLength; ++i) {
        target.draw(myBlocks[i]);
    }

    // Draw meat
    target.draw(myMeat);
}

bool Snake::isGameOver() const {
    return myIsGameOver;
}

void Snake::setDirection(Direction direction) {
    switch(direction) {
        case Left:
            myNextDirection = myDirection == Right ? myNextDirection : direction;
            break;

        case Right:
            myNextDirection = myDirection == Left ? myNextDirection : direction;
            break;

        case Up:
            myNextDirection = myDirection == Down ? myNextDirection : direction;
            break;

        case Down:
            myNextDirection = myDirection == Up ? myNextDirection : direction;
            break;
    }
}
