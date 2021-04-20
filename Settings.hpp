//
//  Settings.hpp
//  Final project (Treasure Hunting Game)
//  TAMK, Programming Languages 2, 20i260E
//  Created by Sviatoslav Vasev on 29.3.2021.
//

#pragma once
#include <iostream>
#include <cstdlib>

class Settings {
public:
    
    //-----------------------------------------------------
    // Symbolic representations of the game objects:
    //-----------------------------------------------------
    
    // ROCK
    static const char SYMBOL_WALL = '#';
    
    // PLAYER
    static const char SYMBOL_PLAYER = 'P';
    
    // MONSTER
    static const char SYMBOL_MONSTER = 'm';
    
    // MAGIC APPLE
    static const char SYMBOL_MAGIC_APPLE = '$';
    
    // MAGIC APPLE
    static const char SYMBOL_GEM = '@';
    
    // DOOR
    static const char SYMBOL_DOOR = 'O';
    
    // SPACE
    static const char SYMBOL_SPACE = '.';
    
    //-----------------------------------------------------
    // Spawn rates
    //-----------------------------------------------------
    
    // How many WALLs to spawn
    static int FORMULA_WALLS(int width, int height) {
        return (width - 2) * (height - 2) / 5;
    };
    
    // How many MONSTERs to spawn
    static int FORMULA_MONSTERS(int level) {
        return level / 3 + 1;
    };
    
    // How many MAGIC APPLEs to spawn
    static int FORMULA_APPLES(int level) {
        return level / 3 + 1;
    };
    
    //-----------------------------------------------------
    // Interactions
    //-----------------------------------------------------
    
    // How much energy is gained when MAGIC APPLE is eaten
    static const int ENERGY_MAGIC_APPLE = 30;
    
    // How much energy is gained when GEM is collected
    static const int STRENGTH_GEM = 3;
    
    // How much energy is gained when GEM is collected
    static const bool CHANCE_WIN() {
        srand(int(time(NULL)));
        return (rand() % 2 == 0);
    }
    
    //-----------------------------------------------------
    // Properties of object
    //-----------------------------------------------------
    
    // What the strength of the MONSTER at spawn is
    static int STRENGTH_MONSTER(int level) {
        return 80 + level*5 + (rand() % 10);
    }
    
    // How much energy is consumed each turn
    static const int ENERGY_PER_TURN = 3;
    
};
