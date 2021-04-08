//
//  Player.hpp
//  Final project (Treasure Hunting Game)
//  TAMK, Programming Languages 2, 20i260E
//  Created by Sviatoslav Vasev on 29.3.2021.
//

#pragma once
#include "GameObject.hpp"
#include "Entity.hpp"

class Player : public Entity, public GameObject {
public:
    
    // Constructor
    Player(int, int);
    
    // Default constructor
    Player();
    
    // Sets the X coordinate
    void setX(int);
    
    // Sets the Y coordinate
    void setY(int);
    
};
