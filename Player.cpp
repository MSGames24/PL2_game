//
//  Player.cpp
//  Final project (Treasure Hunting Game)
//  TAMK, Programming Languages 2, 20i260E
//  Created by Sviatoslav Vasev on 29.3.2021.
//

#include "Player.hpp"
#include "Settings.hpp"

Player::Player(int x, int y) : GameObject(x, y, Settings::SYMBOL_PLAYER){
    this->energy = 100;
    this->strength = 100;
}

// Sets the X coordinate
void Player::setX(int x) {
    if (this->position.getX() != -1 and this->position.getY() != -1) {
        this->energy -= Settings::ENERGY_PER_TURN;
    }
    this->position.setX(x);
}

// Sets the Y coordinate
void Player::setY(int y) {
    if (this->position.getX() != -1 and this->position.getY() != -1) {
        this->energy -= Settings::ENERGY_PER_TURN;
    }
    this->position.setY(y);
}
