//
//  Game.hpp
//  Final project (Treasure Hunting Game)
//  TAMK, Programming Languages 2, 20i260E
//  Created by Sviatoslav Vasev on 6.4.2021.
//

#pragma once
#include "Map.hpp"
#include "Gem.hpp"
#include "MagicApple.hpp"
#include <vector>

class Game {
private:
    
    // Level
    int level;
    
    // Map of the current level
    Map map;
    
    // Player
    Player player;
    
    // Array of monsters
    vector<Monster> monsters;
    
    // Gem
    Gem gem;
    
    // Array of Magic Apples
    vector<MagicApple> apples;
    
protected:
    
    // Spawn objects
    void spawnObjects();
    
    // Render the map with all the objects
    char ** getRenderedMap();
    
    // Print the map with all the objects
    void printMap();
    
    // Process one turn
    void turn(char);
    
    // Go to the next level
    void levelUp();
    
public:
    
    // Constructor
    Game();
    
    // Starts the game
    void start();
    
};
