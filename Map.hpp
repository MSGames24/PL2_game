//
//  map.hpp
//  Final project (Treasure Hunting Game)
//  TAMK, Programming Languages 2, 20i260E
//  Created by Sviatoslav Vasev on 16.2.2021.
//

#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include "Player.hpp"
#include "Monster.hpp"
#include "Settings.hpp"
using namespace std;

class Map {
private:
    // Width of the map
    int width;
    
    // Height of the map
    int height;
    
    // Pointer to the array
    char ** table;
    
    // Door position
    Position doorPosition;

public:
    
    // Constructor
    Map (int);
    
    // Destructor
    ~Map ();
    
    // Copy constructor
    Map (const Map &);
    
    // Assignment operator
    Map& operator= (const Map &);
    
    // Returns the table
    char ** getTable(bool isEaten = false) const;
    
    // Returns the width
    int getWidth();
    
    // Returns the height
    int getHeight();
    
};
