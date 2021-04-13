//
//  GameObject.hpp
//  Final project (Treasure Hunting Game)
//  TAMK, Programming Languages 2, 20i260E
//  Created by Sviatoslav Vasev on 8.4.2021.
//

#pragma once
#include "Position.hpp"
#include "Settings.hpp"

class GameObject {
protected:
    
    // Postion of the object
    Position position;
    
    // Symbol of the object
    char symbol;
    
public:
    
    // Constructor
    GameObject(int, int, char);
    
    // Returns the position
    Position getPosition() const;
    
    // Returns the symbol of the object
    char getSymbol() const;
    
    // Sets the X coordinate
    void virtual setX(int);
    
    // Sets the Y coordinate
    void virtual setY(int);

};
