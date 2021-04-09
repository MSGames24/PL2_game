//
//  Monster.cpp
//  Final project (Treasure Hunting Game)
//  TAMK, Programming Languages 2, 20i260E
//  Created by Sviatoslav Vasev on 29.3.2021.
//

#include "Monster.hpp"

Monster::Monster(int x, int y) : GameObject(x, y, Settings::SYMBOL_MONSTER) {
    this->strength = 100;
    this->energy = 100;
}

// Sets the X coordinate
void Monster::setX(int x) {
    this->position.setX(x);
}

// Sets the Y coordinate
void Monster::setY(int y) {
    this->position.setY(y);
}
