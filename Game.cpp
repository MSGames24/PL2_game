//
//  Game.cpp
//  Final project (Treasure Hunting Game)
//  TAMK, Programming Languages 2, 20i260E
//  Created by Sviatoslav Vasev on 6.4.2021.
//

#include "Game.hpp"

Game::Game() : map(0), player(-1, -1), gem(-1, -1) {
    this->level = 0;
    this->renderedMap = new char*[this->map.getHeight()];
    for (int i = 0; i < this->map.getHeight(); i++) {
        this->renderedMap[i] = new char[this->map.getWidth()];
    }
}

// Destructor
Game::~Game() {
    for (int i = 0; i < this->map.getHeight(); i++) {
        delete [] this->renderedMap[i];
    }
    delete [] this->renderedMap;
}

void Game::start() {
    
    this->spawnObjects();
    this->printMap();
    
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
        this->monsters.push_back(Monster(-1, -1, this->level));
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
void Game::renderMap() {
    // Clean the rendered map
    for (int y = 0; y < this->map.getHeight(); y++) {
        for (int x = 0; x < this->map.getWidth(); x++) {
            this->renderedMap[x][y] = this->map.getTable()[x][y];
        }
    }
    
    // Render the player
    this->renderedMap[this->player.getPosition().getX()][this->player.getPosition().getY()] = this->player.getSymbol();
    
    // Render the monsters
    for (int i = 0; i < monsters.size(); i++) {
        this->renderedMap[this->monsters[i].getPosition().getX()][this->monsters[i].getPosition().getY()] = this->monsters[i].getSymbol();
    }
    
    // Render the gem
    this->renderedMap[this->gem.getPosition().getX()][this->gem.getPosition().getY()] = this->gem.getSymbol();
    
    // Render the magic apples
    for (int i = 0; i < apples.size(); i++) {
        this->renderedMap[this->apples[i].getPosition().getX()][this->apples[i].getPosition().getY()] = this->apples[i].getSymbol();
    }
}

// Print the map with all the objects
void Game::printMap() {
    this->renderMap();
    for (int h = 0; h < this->map.getHeight(); h++) {
        for (int w = 0; w < this->map.getWidth(); w++) {
            cout << this->renderedMap[w][h];
        }
        cout << endl;
    }
    cout << "S: " << this->player.getStrength() << "   E: " << this->player.getEnergy() << endl;
}

// Process one turn
void Game::turn(char direction) {
    this->renderMap();
    
    // Move the player
    switch (direction) {
        case 'w':
            if (this->renderedMap[this->player.getPosition().getX()][this->player.getPosition().getY() - 1] != Settings::SYMBOL_WALL) {
                this->player.setY(this->player.getPosition().getY() - 1);
                this->player.setEnergy(player.getEnergy() - 3);
            }
            break;
            
        case 'a':
            if (this->renderedMap[this->player.getPosition().getX() - 1][this->player.getPosition().getY()] != Settings::SYMBOL_WALL) {
                this->player.setX(this->player.getPosition().getX() - 1);
                this->player.setEnergy(player.getEnergy() - 3);
            }
            break;
        
        case 's':
            if (this->renderedMap[this->player.getPosition().getX()][this->player.getPosition().getY() + 1] != Settings::SYMBOL_WALL) {
                this->player.setY(this->player.getPosition().getY() + 1);
                this->player.setEnergy(player.getEnergy() - 3);
            }
            break;
            
        case 'd':
            if (this->renderedMap[this->player.getPosition().getX() + 1][this->player.getPosition().getY()] != Settings::SYMBOL_WALL) {
                this->player.setX(this->player.getPosition().getX() + 1);
                this->player.setEnergy(player.getEnergy() - 3);
            }
            break;
            
        default:
            break;
    }
    
    // Interact with a monster
    if(this->renderedMap[this->player.getPosition().getX()][this->player.getPosition().getY()] == Settings::SYMBOL_MONSTER) {
        for (int i = 0; i < this->monsters.size(); i++) {
            if (this->monsters[i].getPosition() == this->player.getPosition()) {
                if (this->monsters[i].interact(this->player)) {
                    this->monsters.erase(this->monsters.begin() + i);
                    break;
                } else {
                    break;
                }
            }
        }
    }
    
    // Interact with an apple
    if(this->renderedMap[this->player.getPosition().getX()][this->player.getPosition().getY()] == Settings::SYMBOL_MAGIC_APPLE) {
        for (int i = 0; i < this->apples.size(); i++) {
            if (this->apples[i].getPosition() == this->player.getPosition()) {
                this->apples[i].interact(this->player);
                this->apples.erase(this->apples.begin() + i);
                break;
            }
        }
    }
    
    this->printMap();
}

// Go to the next level
void Game::levelUp() {
    
}
