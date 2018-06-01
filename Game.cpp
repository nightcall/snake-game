#include "Game.hpp"

Game::Game() :
myWindow(sf::VideoMode(800, 600), "My game") {
    myWindow.setFramerateLimit(60);
}

Game::~Game() {

}

bool Game::initialize() {
    if(!myFont.loadFromFile("font.ttf"))
        return false;

    myPointsText.setFont(myFont);
    myPointsText.setString("Points: 0");
    myPointsText.setFillColor(sf::Color::White);
    myPointsText.setCharacterSize(25);
    myPointsText.setPosition(20, 20);

    myGameOverText.setFont(myFont);
    myGameOverText.setString("Game over !");
    myGameOverText.setFillColor(sf::Color::White);
    myGameOverText.setCharacterSize(50);

    sf::FloatRect localBounds = myGameOverText.getLocalBounds();
    myGameOverText.setPosition((WIN_X / 2) - (localBounds.width / 2),
                               (WIN_Y / 2) - (localBounds.height / 2));

    myPressEnterText.setFont(myFont);
    myPressEnterText.setString("Press <enter> to reinitialize");
    myPressEnterText.setFillColor(sf::Color::White);
    myPressEnterText.setCharacterSize(20);
    myPressEnterText.setPosition(20, 50);

    return true;
}

int Game::launch() {
    if(!initialize()) {
        std::cerr << "Could not initialize game" << std::endl;
        return -1;
    }

    sf::Clock clock;

    while(myWindow.isOpen()) {
        sf::Event event;
        myWindow.pollEvent(event);
        if(event.type == sf::Event::Closed) {
            myWindow.close();
        }

        if(event.type == sf::Event::KeyPressed) {
            if(event.key.code == sf::Keyboard::Escape) {
                myWindow.close();
            } else if(event.key.code == sf::Keyboard::Return) {
                mySnake.initialize();
            }
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

        if(clock.getElapsedTime().asSeconds() > 0.2f) {
            if(!mySnake.isGameOver()) {
                clock.restart();
                mySnake.update();
            }
        }

        myWindow.clear();
        myWindow.draw(mySnake);

        // Display points
        myPointsText.setString("Points: " + std::to_string(mySnake.points()));
        myWindow.draw(myPointsText);

        myWindow.draw(myPressEnterText);

        if(mySnake.isGameOver())
            myWindow.draw(myGameOverText);

        myWindow.display();
    }

    return 0;
}
