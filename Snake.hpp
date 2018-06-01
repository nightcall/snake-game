#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Utils.hpp"

#define START_LENGTH    5
#define MAX_LENGTH      100
#define BLOCK_X         20
#define BLOCK_Y         20
#define WIN_X           800
#define WIN_Y           600
#define NUM_BLOCKS_X    (WIN_X / BLOCK_X)
#define NUM_BLOCKS_Y    (WIN_Y / BLOCK_Y)

enum Direction {
	Right,
	Left,
	Up,
	Down
};

class Snake : public sf::Drawable {
	public:
		Snake();
		~Snake();
        void initialize();
		void update();
		void setDirection(Direction direction);
		bool isBlockInSnake(sf::Vector2f) const;
		void generateNextMeat();
        bool isGameOver() const;
        unsigned int points() const;

	private:
        unsigned int        myPoints;
        bool                myIsGameOver;
		Direction           myDirection;
		Direction           myNextDirection;
		unsigned int        myLength;
		sf::RectangleShape  myBlocks[MAX_LENGTH];
		sf::RectangleShape  myMeat;

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
#endif // SNAKE_HPP
