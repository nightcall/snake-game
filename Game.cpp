#include "Game.hpp"

Game::Game() :
myWindow(sf::VideoMode(800, 600), "My game") {
    myWindow.setFramerateLimit(60);
}

Game::~Game() {

}

int Game::launch() {
    sf::Clock clock;

    while(myWindow.isOpen()) {
        sf::Event event;
        myWindow.pollEvent(event);
        if(event.type == sf::Event::Closed) {
            myWindow.close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            mySnake.setDirection(Left);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            mySnake.setDirection(Right);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            mySnake.setDirection(Up);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            mySnake.setDirection(Down);
        }

        if(clock.getElapsedTime().asSeconds() > 1.f) {
            clock.restart();
            mySnake.update();
        }

        myWindow.clear();
        myWindow.draw(mySnake);
        myWindow.display();
    }

    return 0;
}
