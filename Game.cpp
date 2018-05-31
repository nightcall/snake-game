#include "Game.hpp"

Game::Game() :
myWindow(sf::VideoMode(800, 600), "My game") {
    myWindow.setFramerateLimit(60);
}

Game::~Game() {

}

int Game::launch() {
    while(myWindow.isOpen()) {
        sf::Event event;
        myWindow.pollEvent(event);
        if(event.type == sf::Event::Closed) {
            myWindow.close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            mySnake.update();
        }

        myWindow.clear();
        myWindow.draw(mySnake);
        myWindow.display();
    }

    return 0;
}
