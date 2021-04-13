//
//  Entity.cpp
//  Final project (Treasure Hunting Game)
//  TAMK, Programming Languages 2, 20i260E
//  Created by Sviatoslav Vasev on 29.3.2021.
//

#include "Entity.hpp"

// Default constructor
Entity::Entity() {
    
}

// Returns the strength
int Entity::getStrength() const {
    return this->strength;
}

// Returns the energy
int Entity::getEnergy() const {
    return this->energy;
}

// Sets the energy
void Entity::setEnergy(int energy) {
    this->energy = energy;
}

// Sets the strength
void Entity::setStrength(int strength) {
    this->strength = strength;
}
