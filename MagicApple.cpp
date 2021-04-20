//
//  MagicApple.cpp
//  Final project (Treasure Hunting Game)
//  TAMK, Programming Languages 2, 20i260E
//  Created by Sviatoslav Vasev on 9.4.2021.
//

#include "MagicApple.hpp"

MagicApple::MagicApple(int x, int y) : GameObject(x, y, Settings::SYMBOL_MAGIC_APPLE) {
    // A value from the one in settings + >10
    srand(int(time(NULL)));
    this->value = rand() % 11 + Settings::ENERGY_MAGIC_APPLE;
}

// Interact with the player
void MagicApple::interact(Player &player) {
    if (player.getEnergy() + this->value > 100) {
        player.setEnergy(100);
    } else {
        player.setEnergy(player.getEnergy() + this->value);
    }
}
