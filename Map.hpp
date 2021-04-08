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
#include "GameObject.hpp"
#include "Player.hpp"
#include "Monster.hpp"
#include "Wall.hpp"
#include "Space.hpp"
using namespace std;

class Map {
private:
    // Width of the map
    int width;
    
    // Height of the map
    int height;
    
    // Pointer to the array
    GameObject ** table;
    
    // Changes one character to the passed value
    void set(int, int, GameObject *);

public:
    
    // Constructor
    Map (int, Player *);
    
    // Default constructor
    Map();
    
    // Destructor
    ~Map ();
    
    // Copy constructor
    Map (const Map &);
    
    // Assignment operator
    Map& operator= (const Map &);
    
    // Prints the table
    void print() const;
    
    // Moves the entity
    void moveObject(GameObject &, char);
    
    // Returns the char at the given coordinates
    GameObject &getElementAt(int, int) const;
    
    // Returns the char at the given position
    GameObject &getElementAt(Position) const;
    
    // Returns the player
    GameObject &getPlayer() const;
    
};
