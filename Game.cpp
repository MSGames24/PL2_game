//
//  Game.cpp
//  Final project (Treasure Hunting Game)
//  TAMK, Programming Languages 2, 20i260E
//  Created by Sviatoslav Vasev on 6.4.2021.
//

#include "Game.hpp"

Game::Game() : map(0, new Player(0, 0)){
    this->level = 0;
}

void Game::start() {
    
    // Process the movement
    char choice[1];
    do {
        // Print the map
        this->map.print();
        
        cout << "Please enter movement (wasd) or q to escape > ";
        cin.get(choice, 2);
        cin.clear();
        cin.ignore(123, '\n');
        
        switch (choice[0]) {
            case 'w':
                cout << "You pressed w" << endl;
                map.moveObject(map.getPlayer(), 'w');
                break;
            case 'a':
                cout << "You pressed a" << endl;
                break;
            case 's':
                cout << "You pressed s" << endl;
                break;
            case 'd':
                cout << "You pressed d" << endl;
                break;
            case 'q':
                cout << "Finished" << endl;
                break;
            default:
                cout << "Unknown input: " << choice[0] << endl;
        }
        
    } while (choice[0] != 'q');
}
