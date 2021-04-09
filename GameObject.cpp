//
//  GameObject.cpp
//  Final project (Treasure Hunting Game)
//  TAMK, Programming Languages 2, 20i260E
//  Created by Sviatoslav Vasev on 8.4.2021.
//

#include "GameObject.hpp"

// Constructor
GameObject::GameObject(int x, int y, char symbol) {
    this->position.setX(x);
    this->position.setY(y);
    this->symbol = symbol;
}

// Returns the position
Position GameObject::getPosition() const {
    return this->position;
}

// Returns the symbol of the object
char GameObject::getSymbol() const {
    return this->symbol;
}

// Sets the X coordinate
void GameObject::setX(int x) {
    if (this->position.getX() == -1) {
        this->position.setX(x);
    }
}

// Sets the Y coordinate
void GameObject::setY(int y) {
    if (this->position.getY() == -1) {
        this->position.setY(y);
    }
}
