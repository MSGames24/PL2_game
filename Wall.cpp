//
//  Wall.cpp
//  Final project (Treasure Hunting Game)
//  TAMK, Programming Languages 2, 20i260E
//  Created by Sviatoslav Vasev on 29.3.2021.
//

#include "Wall.hpp"
#include "GameObject.hpp"

Wall::Wall(int x, int y) : GameObject(x, y, Settings::SYMBOL_WALL)
{   }

// Returns the type of the object
ObjectType Wall::getType() const {
    return WallType;
}
