//
//  MagicApple.hpp
//  Final project (Treasure Hunting Game)
//  TAMK, Programming Languages 2, 20i260E
//  Created by Sviatoslav Vasev on 9.4.2021.
//

#pragma once
#include "Player.hpp"
class MagicApple : public GameObject {
private:
    
    //  Value of the Magic Apple: how much it adds to the strength when eaten
    int value;
    
public:
    
    //  Constructor
    MagicApple(int, int);
    
    // Interact with the player
    void interact(Player &);
    
};
