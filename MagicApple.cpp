//
//  MagicApple.cpp
//  Final project (Treasure Hunting Game)
//  TAMK, Programming Languages 2, 20i260E
//  Created by Sviatoslav Vasev on 9.4.2021.
//

#include "MagicApple.hpp"

MagicApple::MagicApple(int x, int y) : GameObject(x, y, Settings::SYMBOL_MAGIC_APPLE) {
    // Random value from 5 to 15
    srand(int(time(NULL)));
    this->value = rand() % 11 + 5;
}
