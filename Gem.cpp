//
//  Gem.cpp
//  Final project (Treasure Hunting Game)
//  TAMK, Programming Languages 2, 20i260E
//  Created by Sviatoslav Vasev on 9.4.2021.
//

#include "Gem.hpp"

Gem::Gem(int x, int y) : GameObject(x, y, Settings::SYMBOL_GEM) {
    
}

// Interact with the player
void Gem::interact(Player &player) {
    player.setStrength(player.getStrength() + Settings::STRENGTH_GEM);
}
