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
#include <iostream>

Cannon::Cannon() {
    _charging = false;
    _goingUp = true;
    _chargingUp = true;
    _angle = 0;
    _charge = 0;
    _position = sf::Vector2f(0, 1080);
    _shape = sf::RectangleShape(_position);
    _chargeShape = sf::RectangleShape(_position);
    
    _shape.setSize(sf::Vector2f(200, 20));
    _shape.setPosition(_position);
    _shape.setFillColor(sf::Color::Green);
    
    _chargeShape.setSize(sf::Vector2f(0, 20));
    _chargeShape.setPosition(_position);
    _chargeShape.setFillColor(sf::Color::Red);
}

void Cannon::update() {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        _charging = true;
    } else {
        if (_charging) {
            shoot();
        }
    }
    
    if (_charging) {
        charge();
    } else {
        move();
    }
    
}

void Cannon::draw() {
    GameManager::Instance()->window()->draw(_shape);
    GameManager::Instance()->window()->draw(_chargeShape);
}

void Cannon::shoot() {
    _charging = false;
    _charge = 0;
    _chargingUp = true;
//    _chargeShape.setSize(sf::Vector2f(_shape.getSize().x * _charge / 100, _shape.getSize().y));
    std::cout << "peew pew pew \n";
}

void Cannon::move() {
    if (_goingUp) {
        _angle += 1.0;
    } else {
        _angle -= 1.0;
    }
    
    if (_angle <= 0 || _angle >= 90) {
        _goingUp = !_goingUp;
    }
    _shape.setRotation(-_angle);
    _chargeShape.setRotation(-_angle);
}

void Cannon::charge() {
    if (_chargingUp) {
        _charge += 5;
    } else {
        _charge -= 5;
    }
    
    if (_charge == 0 || _charge == 100) {
        _chargingUp = !_chargingUp;
    }
    _chargeShape.setSize(sf::Vector2f(_shape.getSize().x * _charge / 100, _shape.getSize().y));
    std::cout << "charge shape: " << _chargeShape.getSize().x << ", " <<  _chargeShape.getSize().y << "\n";
}
