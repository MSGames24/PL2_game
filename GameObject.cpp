//
//  GameObject.cpp
//  Final project (Treasure Hunting Game)
//  TAMK, Programming Languages 2, 20i260E
//  Created by Sviatoslav Vasev on 29.3.2021.
//

#include "GameObject.hpp"

// Constructor
GameObject::GameObject(int x, int y, char symbol) {
    this->symbol = symbol;
    this->position.set(x, y);
}

GameObject::GameObject()
{   }

char GameObject::getSymbol() const {
    return this->symbol;
}

Position GameObject::getPosition() const {
    return this->position;
}

// Returns the X coordinate
int GameObject::getX() const {
    return this->position.getX();
}

// Returns the Y coordinate
int GameObject::getY() const {
    return this->position.getY();
}

// Returns the type of the object
ObjectType GameObject::getType() const {
    return GameObjectType;
}
