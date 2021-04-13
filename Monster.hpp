//
//  Monster.hpp
//  Final project (Treasure Hunting Game)
//  TAMK, Programming Languages 2, 20i260E
//  Created by Sviatoslav Vasev on 29.3.2021.
//

#pragma once
#include "Entity.hpp"
#include "Player.hpp"
class Monster : public Entity, public GameObject {
public:
    
    // Constructor
    Monster(int, int, int);
    
    // Sets the X coordinate
    void setX(int) override;
    
    // Sets the Y coordinate
    void setY(int) override;
    
    // Interact with the player
    bool interact(Player &);
};
