//
//  Wall.hpp
//  Final project (Treasure Hunting Game)
//  TAMK, Programming Languages 2, 20i260E
//  Created by Sviatoslav Vasev on 29.3.2021.
//

#pragma once
#include "GameObject.hpp"

class Wall : public GameObject {
public:
    
    // Constructor
    Wall(int, int);
    
    // Returns the type of the object
    ObjectType getType() const override;
    
};
