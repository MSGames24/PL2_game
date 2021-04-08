//
//  Position.cpp
//  Assignment 5 (A05_4)
//  TAMK, Programming Languages 2, 20i260E
//  Created by Sviatoslav Vasev on 16.2.2021.
//

#include "Position.hpp"

// Constructor
Position::Position(int x, int y) {
    this->x = x;
    this->y = y;
}

Position::Position () : Position(1, 1)
{   };

// Operator ==
bool Position::operator== (const Position &right) {
    return ((this->x == right.getX()) and (this->y == right.getY()));
}

// Operator !=
bool Position::operator!= (const Position &right) {
    return not(*this == right);
}

// Set the position when two coordinates given
void Position::set (int x, int y) {
    this->x = x;
    this->y = y;
}

// Set the positin when x coordinate given
void Position::setX (int x) {
    this->x = x;
}

// Set the positin when y coordinate given
void Position::setY (int y) {
    this->y = y;
}

// Returns the x coordinate
int Position::getX () const {
    return this->x;
}

// Returns the y coordinate
int Position::getY () const {
    return this->y;
}
