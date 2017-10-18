//
//  GameManager.cpp
//  TurtleShot
//
//  Created by Michał Kiełek on 18.10.2017.
//  Copyright © 2017 Michał Kiełek. All rights reserved.
//

#include "GameManager.hpp"
#include "Game.hpp"
#include <cstdlib>
#include <ctime>


GameManager* GameManager::_Instance = NULL;

GameManager* GameManager::Instance()
{
    if (!_Instance)
        _Instance = new GameManager;
    
    return _Instance;
}

GameManager::GameManager() {
    srand(time(NULL));
    _game = new Game();
}

Game* GameManager::game() {
    return _game;
}

sf::RenderWindow* GameManager::window() {
    return _game->window();
}