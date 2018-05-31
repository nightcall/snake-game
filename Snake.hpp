#ifndef SNAKE_HPP
#define SNAKE_HPP

#define MAX_BLOCKS 100

class Snake {
    public:
        Snake();
        ~Snake();

    private:
        unsigned int    myLength;
        sf::Vector2i    myBlocks[MAX_BLOCKS];
};
#endif // SNAKE_HPP
