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
    sf::Vector2f _position;
    float _angle;
    sf::RectangleShape _shape;
    bool _goingUp;
};

#endif /* Cannon_hpp */
