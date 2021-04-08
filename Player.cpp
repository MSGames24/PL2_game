//
//  Player.cpp
//  Final project (Treasure Hunting Game)
//  TAMK, Programming Languages 2, 20i260E
//  Created by Sviatoslav Vasev on 29.3.2021.
//

#include "Player.hpp"
#include "GameObject.hpp"

Player::Player(int x, int y) : GameObject(x, y, Settings::SYMBOL_PLAYER) {
    
}

Player::Player() {
    
}

// Sets the X coordinate
void Player::setX(int x) {
    this->position.setX(x);
}

// Sets the Y coordinate
void Player::setY(int y) {
    this->position.setY(y);
}
