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
#include "Logger.hpp"
#include <vector>

class Game {
private:
    
    // Level
    int level;
    
    // Shows if the game is running
    bool isRunning;
    
    // Logs the events
    Logger logger;
    
    // Map of the current level
    Map * map;
    
    // Rendered map of the current level
    char ** renderedMap;
    
    // Player
    Player player;
    
    // Array of monsters
    vector<Monster> monsters;
    
    // Array of Gems
    vector<Gem> gems;
    
    // Array of Magic Apples
    vector<MagicApple> apples;
    
protected:
    
    // Spawn objects
    void spawnObjects();
    
    // Render the map with all the objects
    void renderMap();
    
    // Print the map with all the objects
    void printMap();
    
    // Process one turn
    void turn(char);
    
    // Open the door after collecting the gem
    void openDoor();
    
    // Go to the next level
    void levelUp();
    
    // Ends the game
    void end();
    
public:
    
    // Constructor
    Game();
    
    // Destructor
    ~Game();
    
    // Starts the game
    void start();
    
};
