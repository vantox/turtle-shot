//
//  Cannon.cpp
//  TurtleShot
//
//  Created by Michał Kiełek on 18.10.2017.
//  Copyright © 2017 Michał Kiełek. All rights reserved.
//

#include "Cannon.hpp"
#include "GameManager.hpp"
#include <SFML/Graphics.hpp>

Cannon::Cannon() {
    _goingUp = true;
    _angle = 0;
    _position = sf::Vector2f(0, 1080);
    _shape = sf::RectangleShape(_position);
    
    _shape.setSize(sf::Vector2f(200, 20));
    _shape.setPosition(_position);
    _shape.setFillColor(sf::Color::Green);
}

void Cannon::update() {
    if (_goingUp) {
        _angle += 1.0;
    } else {
        _angle -= 1.0;
    }
    
    if (_angle <= 0 || _angle >= 90) {
        _goingUp = !_goingUp;
    }
    _shape.setRotation(-_angle);
}

void Cannon::draw() {
    GameManager::Instance()->window()->draw(_shape);
}