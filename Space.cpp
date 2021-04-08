//
//  Space.cpp
//  Final project (Treasure Hunting Game)
//  TAMK, Programming Languages 2, 20i260E
//  Created by Sviatoslav Vasev on 29.3.2021.
//

#include "Space.hpp"
#include "GameObject.hpp"

Space::Space(int x, int y) : GameObject(x, y, Settings::SYMBOL_SPACE)
{   }

// Returns the type of the object
ObjectType Space::getType() const {
    return SpaceType;
}
