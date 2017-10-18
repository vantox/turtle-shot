//
//  Game.hpp
//  TurtleShot
//
//  Created by Michał Kiełek on 18.10.2017.
//  Copyright © 2017 Michał Kiełek. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "Cannon.hpp"

class Game {
public:
    Game();
    void update();
    void draw();
    void run();
    sf::RenderWindow* window();
    
private:
    sf::RenderWindow* _window;
    Cannon* _cannon;
};

#endif /* Game_hpp */
