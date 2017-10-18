//
//  Game.cpp
//  TurtleShot
//
//  Created by Michał Kiełek on 18.10.2017.
//  Copyright © 2017 Michał Kiełek. All rights reserved.
//

#include "Game.hpp"

Game::Game() {
    _window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "TurtleShot");
    _window->setFramerateLimit(60);
    _cannon = new Cannon();
}

void Game::update() {
    _cannon->update();
}

void Game::draw() {
    _cannon->draw();
}

void Game::run() {
    // Start the game loop
    while (_window->isOpen())
    {
        // Process events
        sf::Event event;
        while (_window->pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                _window->close();
            }
            
            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                _window->close();
            }
        }
        
        // Clear screen
        _window->clear();
        
        update();
        
        draw();
        
        // Update the window
        _window->display();
    }
}

sf::RenderWindow* Game::window() {
    return _window;
}