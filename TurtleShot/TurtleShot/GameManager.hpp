//
//  GameManager.hpp
//  TurtleShot
//
//  Created by Michał Kiełek on 18.10.2017.
//  Copyright © 2017 Michał Kiełek. All rights reserved.
//

#ifndef GameManager_hpp
#define GameManager_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

class Game;

class GameManager {
public:
    static GameManager* Instance();
    Game* game();
    sf::RenderWindow* window();
    
private:
    GameManager();
    GameManager(GameManager const&){};
    GameManager& operator=(GameManager const&){};
    static GameManager* _Instance;
    Game* _game;
    
};

#endif /* GameManager_hpp */
