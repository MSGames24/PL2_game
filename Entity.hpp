//
//  Entity.hpp
//  Final project (Treasure Hunting Game)
//  TAMK, Programming Languages 2, 20i260E
//  Created by Sviatoslav Vasev on 29.3.2021.
//

#pragma once
#include "Position.hpp"

class Entity {
private:
    
    // The strength of the object
    int strength;
    
    // The energy of the object
    int energy;
    
public:
    
    // Constructor
    Entity(int, int, char);
    
    // Default constructor
    Entity();
    
    // Returns the strength
    int getStrength() const;
    
    // Returns the energy
    int getEnergy() const;
    
    // Sets the energy
    void setEnergy();
    
    // Sets the strength
    void setStrength();
    
};
