//
//  Cannon.hpp
//  TurtleShot
//
//  Created by Michał Kiełek on 18.10.2017.
//  Copyright © 2017 Michał Kiełek. All rights reserved.
//

#ifndef Cannon_hpp
#define Cannon_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

class Cannon {
public:
    Cannon();
    void update();
    void draw();
    
private:
    void shoot();
    void charge();
    void move();
    sf::Vector2f _position;
    float _angle;
    sf::RectangleShape _shape;
    sf::RectangleShape _chargeShape;
    bool _goingUp;
    bool _charging;
    bool _chargingUp;
    int _charge;
};

#endif /* Cannon_hpp */
