//
//  Game.hpp
//  Final project (Treasure Hunting Game)
//  TAMK, Programming Languages 2, 20i260E
//  Created by Sviatoslav Vasev on 6.4.2021.
//

#pragma once
#include "Map.hpp"

class Game {
private:
    
    // Level
    int level;
    
    // Map of the current level
    Map map;
    
public:
    
    // Constructor
    Game();
    
    // Starts the game
    void start();
    
    // Go to the next level
    void levelUp();
    
};
