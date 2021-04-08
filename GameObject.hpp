//
//  GameObject.hpp
//  Final project (Treasure Hunting Game)
//  TAMK, Programming Languages 2, 20i260E
//  Created by Sviatoslav Vasev on 29.3.2021.
//

#pragma once
#include "Position.hpp"
#include "Settings.hpp"

enum ObjectType {GameObjectType, WallType, SpaceType, PlayerType, MonsterType};

class GameObject {
private:
    
    // Symbolic representation of an object
    char symbol;
    
protected:
    
    // Position of an object
    Position position;
    
public:
    
    // Constructor
    GameObject(int, int, char);
    
    // Constructor
    GameObject();

    // Returns the symbol of the object
    char getSymbol() const;
    
    // Returns the position
    Position getPosition() const;
    
    // Returns the X coordinate
    int getX() const;
    
    // Returns the Y coordinate
    int getY() const;
    
    // Returns the type of the object
    virtual ObjectType getType() const;
    
};
