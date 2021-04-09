//
//  Settings.hpp
//  Final project (Treasure Hunting Game)
//  TAMK, Programming Languages 2, 20i260E
//  Created by Sviatoslav Vasev on 29.3.2021.
//

#pragma once
#include <iostream>

class Settings {
public:
    
    // Symbolic representations of the game objects:
    
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
    
    //
    
    // How often walls spawn
    static int FORMULA_WALLS(int width, int height) {
        return (width - 2) * (height - 2) / 5;
    };
    
    // How many monsters to spawn
    static int FORMULA_MONSTERS(int level) {
        return level / 3 + 1;
    };
    
    // How many magic apples to spawn
    static int FORMULA_APPLES(int level) {
        return level / 3 + 1;
    };
};
