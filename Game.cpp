//
//  Game.cpp
//  Final project (Treasure Hunting Game)
//  TAMK, Programming Languages 2, 20i260E
//  Created by Sviatoslav Vasev on 6.4.2021.
//

#include "Game.hpp"

Game::Game() : map(-1), player(-1, -1), gem(-1, -1) {
    this->level = 0;
}

void Game::start() {
    
    this->spawnObjects();
    
    // Process the movement
    char choice[1];
    do {
        cout << "Please enter movement (wasd) or q to escape > ";
        cin.get(choice, 2);
        cin.clear();
        cin.ignore(123, '\n');
        
        switch (choice[0]) {
            case 'w':
            case 'a':
            case 's':
            case 'd':
                this->turn(choice[0]);
                break;
            case 'q':
                cout << "Finished" << endl;
                break;
            default:
                cout << "Unknown input: " << choice[0] << endl;
        }
        
    } while (choice[0] != 'q');
}

// Spawn objects
void Game::spawnObjects() {
    
    // Replace the gem
    this->gem = Gem(-1, -1);
    
    // Add monsters
    this->monsters.clear();
    for (int i = 0; i < Settings::FORMULA_MONSTERS(this->level); i++) {
        this->monsters.push_back(Monster(-1, -1));
    }
    
    // Add magic apples
    this->apples.clear();
    for (int i = 0; i < Settings::FORMULA_APPLES(this->level); i++) {
        this->apples.push_back(MagicApple(-1, -1));
    }
    
    Map newMap = this->map;
    char ** emptyMap = newMap.getTable();
    
    // Spawn player
    for (int y = this->map.getHeight() / 2; y < this->map.getHeight(); y++) {
        for (int x = this->map.getWidth() / 2; x < this->map.getWidth(); x++) {
            if (emptyMap[x][y] == Settings::SYMBOL_SPACE) {
                this->player.setX(x);
                this->player.setY(y);
                emptyMap[x][y] = Settings::SYMBOL_PLAYER;
                goto spawnGems;
            }
        }
    }
    
    spawnGems:
    // Spawn monsters
    srand(int(time(NULL)));
    for (int i = 0; i < this->monsters.size(); i++) {
        while (true) {
            // Get random coordinates
            int x = rand() % (this->map.getWidth() - 2) + 1;
            int y = rand() % (this->map.getHeight() - 2) + 1;
            
            if (emptyMap[x][y] == Settings::SYMBOL_SPACE) {
                this->monsters[i].setX(x);
                this->monsters[i].setY(y);
                emptyMap[x][y] = Settings::SYMBOL_MONSTER;
                break;
            }
        }
    }
    
    // Spawn gem
    while (true) {
        // Get random coordinates
        int x = rand() % (this->map.getWidth() - 2) + 1;
        int y = rand() % (this->map.getHeight() - 2) + 1;
        
        if (emptyMap[x][y] == Settings::SYMBOL_SPACE) {
            this->gem.setX(x);
            this->gem.setY(y);
            emptyMap[x][y] = Settings::SYMBOL_GEM;
            break;
        }
    }
    
    // Spawn magic apples
    for (int i = 0; i < this->apples.size(); i++) {
        while (true) {
            // Get random coordinates
            int x = rand() % (this->map.getWidth() - 2) + 1;
            int y = rand() % (this->map.getHeight() - 2) + 1;
            
            if (emptyMap[x][y] == Settings::SYMBOL_SPACE) {
                this->apples[i].setX(x);
                this->apples[i].setY(y);
                emptyMap[x][y] = Settings::SYMBOL_MAGIC_APPLE;
                break;
            }
        }
    }
}

// Render the map with all the objects
char ** Game::getRenderedMap() {
    Map mapCopy = this->map;
    char ** table = mapCopy.getTable();
    
    // Render the player
    table[this->player.getPosition().getX()][this->player.getPosition().getY()] = this->player.getSymbol();
    
    // Render the monsters
    for (int i = 0; i < monsters.size(); i++) {
        table[this->monsters[i].getPosition().getX()][this->monsters[i].getPosition().getY()] = this->monsters[i].getSymbol();
    }
    
    // Render the gem
    table[this->gem.getPosition().getX()][this->gem.getPosition().getY()] = this->gem.getSymbol();
    
    // Render the magic apples
    for (int i = 0; i < apples.size(); i++) {
        table[this->apples[i].getPosition().getX()][this->apples[i].getPosition().getY()] = this->apples[i].getSymbol();
    }
    
    for (int h = 0; h < this->map.getHeight(); h++) {
        for (int w = 0; w < this->map.getWidth(); w++) {
            cout << table[w][h];
        }
        cout << endl;
    }
    
    return table;
}

// Print the map with all the objects
void Game::printMap() {
    char ** table = this->getRenderedMap();
    
    for (int h = 0; h < this->map.getHeight(); h++) {
        for (int w = 0; w < this->map.getWidth(); w++) {
            cout << table[w][h];
        }
        cout << endl;
    }
}

// Process one turn
void Game::turn(char direction) {
    this->printMap();
}

// Go to the next level
void Game::levelUp() {
    
}
