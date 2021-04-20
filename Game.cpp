//
//  Game.cpp
//  Final project (Treasure Hunting Game)
//  TAMK, Programming Languages 2, 20i260E
//  Created by Sviatoslav Vasev on 6.4.2021.
//

#include "Game.hpp"

Game::Game() : player(-1, -1) {
    this->isRunning = true;
    this->level = 0;
    this->map = new Map(this->level);
    this->renderedMap = new char*[this->map->getHeight()];
    for (int i = 0; i < this->map->getHeight(); i++) {
        this->renderedMap[i] = new char[this->map->getWidth()];
    }
}

// Destructor
Game::~Game() {
    for (int i = 0; i < this->map->getHeight(); i++) {
        delete [] this->renderedMap[i];
    }
    delete [] this->renderedMap;
    delete this->map;
}

// Starts the game loop
void Game::start() {
    this->logger.add("The game started");
    
    this->spawnObjects();
    this->printMap();
    
    // Process the movement
    string choice;
    do {
        cout << "Please enter movement (wasd) or q to escape > ";
        cin >> choice;
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
                this->end();
                break;
            default:
                cout << "Unknown input: " << choice[0] << endl;
        }
        
    } while (this->isRunning);
    
    this->logger.print();
}

// Spawn objects
void Game::spawnObjects() {
    
    // Replace the gem
    this->gems.clear();
    this->gems.push_back(Gem(-1, -1));
    
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
    
    Map newMap = *this->map;
    char ** emptyMap = newMap.getTable();
    
    // Spawn player
    for (int y = this->map->getHeight() / 2; y < this->map->getHeight(); y++) {
        for (int x = this->map->getWidth() / 2; x < this->map->getWidth(); x++) {
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
            int x = rand() % (this->map->getWidth() - 2) + 1;
            int y = rand() % (this->map->getHeight() - 2) + 1;
            
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
        int x = rand() % (this->map->getWidth() - 2) + 1;
        int y = rand() % (this->map->getHeight() - 2) + 1;
        
        if (emptyMap[x][y] == Settings::SYMBOL_SPACE) {
            this->gems[0].setX(x);
            this->gems[0].setY(y);
            emptyMap[x][y] = Settings::SYMBOL_GEM;
            break;
        }
    }
    // Spawn magic apples
    for (int i = 0; i < this->apples.size(); i++) {
        while (true) {
            // Get random coordinates
            int x = rand() % (this->map->getWidth() - 2) + 1;
            int y = rand() % (this->map->getHeight() - 2) + 1;
            
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
    for (int y = 0; y < this->map->getHeight(); y++) {
        for (int x = 0; x < this->map->getWidth(); x++) {
            this->renderedMap[x][y] = this->map->getTable()[x][y];
        }
    }
    
    // Render the player
    this->renderedMap[this->player.getPosition().getX()][this->player.getPosition().getY()] = this->player.getSymbol();
    
    // Render the monsters
    for (int i = 0; i < monsters.size(); i++) {
        this->renderedMap[this->monsters[i].getPosition().getX()][this->monsters[i].getPosition().getY()] = this->monsters[i].getSymbol();
    }
    
    // Render the gem
    for (int i = 0; i < gems.size(); i++) {
        this->renderedMap[this->gems[i].getPosition().getX()][this->gems[i].getPosition().getY()] = this->gems[i].getSymbol();
    }
    
    // Render the magic apples
    for (int i = 0; i < apples.size(); i++) {
        this->renderedMap[this->apples[i].getPosition().getX()][this->apples[i].getPosition().getY()] = this->apples[i].getSymbol();
    }
}

// Print the map with all the objects
void Game::printMap() {
    this->renderMap();
    for (int h = 0; h < this->map->getHeight(); h++) {
        for (int w = 0; w < this->map->getWidth(); w++) {
            cout << this->renderedMap[w][h];
        }
        cout << endl;
    }
    cout << "S: " << this->player.getStrength() << "   E: " << this->player.getEnergy() << "   Level: " << this->level << endl;
}

// Process one turn
void Game::turn(char direction) {
    this->renderMap();
    
    // Move the player
    switch (direction) {
        case 'w':
            if (this->renderedMap[this->player.getPosition().getX()][this->player.getPosition().getY() - 1] != Settings::SYMBOL_WALL) {
                this->player.setY(this->player.getPosition().getY() - 1);
            }
            break;
            
        case 'a':
            if (this->renderedMap[this->player.getPosition().getX() - 1][this->player.getPosition().getY()] != Settings::SYMBOL_WALL) {
                this->player.setX(this->player.getPosition().getX() - 1);
            }
            break;
        
        case 's':
            if (this->renderedMap[this->player.getPosition().getX()][this->player.getPosition().getY() + 1] != Settings::SYMBOL_WALL) {
                this->player.setY(this->player.getPosition().getY() + 1);
            }
            break;
            
        case 'd':
            if (this->renderedMap[this->player.getPosition().getX() + 1][this->player.getPosition().getY()] != Settings::SYMBOL_WALL) {
                this->player.setX(this->player.getPosition().getX() + 1);
            }
            break;
            
        default:
            break;
    }
    
    // Interact with a Monster
    if(this->renderedMap[this->player.getPosition().getX()][this->player.getPosition().getY()] == Settings::SYMBOL_MONSTER) {
        for (int i = 0; i < this->monsters.size(); i++) {
            if (this->monsters[i].getPosition() == this->player.getPosition()) {
                if (this->monsters[i].interact(this->player)) {
                    this->monsters.erase(this->monsters.begin() + i);
                    this->logger.add("Slayed a monster");
                    break;
                } else {
                    this->player.setEnergy(0);
                    this->logger.add("Got slayed by monster");
                    this->end();
                    break;
                }
            }
        }
    }
    
    // Interact with a Magic Apple
    if(this->renderedMap[this->player.getPosition().getX()][this->player.getPosition().getY()] == Settings::SYMBOL_MAGIC_APPLE) {
        for (int i = 0; i < this->apples.size(); i++) {
            if (this->apples[i].getPosition() == this->player.getPosition()) {
                this->apples[i].interact(this->player);
                this->apples.erase(this->apples.begin() + i);
                this->logger.add("Ate a magic apple");
                break;
            }
        }
    }
    
    // Interact with a Gem
    if(this->renderedMap[this->player.getPosition().getX()][this->player.getPosition().getY()] == Settings::SYMBOL_GEM) {
        for (int i = 0; i < this->gems.size(); i++) {
            if (this->gems[i].getPosition() == this->player.getPosition()) {
                this->gems[i].interact(this->player);
                this->gems.erase(this->gems.begin() + i);
                this->openDoor();
                this->logger.add("Found a gem");
                break;
            }
        }
        
    }
    
    // Interact with the Door
    if(this->renderedMap[this->player.getPosition().getX()][this->player.getPosition().getY()] == Settings::SYMBOL_DOOR) {
        this->levelUp();
    }
    
    // Move the monsters
    for (int i = 0; i < this->monsters.size(); i++) {
        // Check the energy of the monster
        if (this->monsters[i].getEnergy() <= 0) {
            this->monsters.erase(this->monsters.begin() + i);
            this->logger.add("Monster died");
            i--;
        // If the player is near the monster it'll try to attack
        } else if (((abs(this->monsters[i].getPosition().getX() - this->player.getPosition().getX()) <= 1) and (abs(this->monsters[i].getPosition().getY() - this->player.getPosition().getY()) == 0)) or ((abs(this->monsters[i].getPosition().getY() - this->player.getPosition().getY()) <= 1) and (abs(this->monsters[i].getPosition().getX() - this->player.getPosition().getX()) == 0))) {
            if (this->monsters[i].interact(this->player)) {
                this->monsters.erase(this->monsters.begin() + i);
                this->logger.add("Slayed a monster");
                break;
            } else {
                this->player.setEnergy(0);
                this->logger.add("Got slayed by a monster");
                this->end();
                break;
            }
        // If there's no player near the monster, it will move randomly
        } else {
            srand(int(time(NULL)));
            switch (rand() % 4) {
                case 0:
                    if (this->renderedMap[this->monsters[i].getPosition().getX()][this->monsters[i].getPosition().getY() - 1] == Settings::SYMBOL_SPACE) {
                        this->monsters[i].setY(this->monsters[i].getPosition().getY() - 1);
                        break;
                    }
                case 1:
                    if (this->renderedMap[this->monsters[i].getPosition().getX()][this->monsters[i].getPosition().getY() + 1] == Settings::SYMBOL_SPACE) {
                        this->monsters[i].setY(this->monsters[i].getPosition().getY() + 1);
                        break;
                    }
                case 2:
                    if (this->renderedMap[this->monsters[i].getPosition().getX() - 1][this->monsters[i].getPosition().getY()] == Settings::SYMBOL_SPACE) {
                        this->monsters[i].setX(this->monsters[i].getPosition().getX() - 1);
                        break;
                    }
                case 3:
                    if (this->renderedMap[this->monsters[i].getPosition().getX() + 1][this->monsters[i].getPosition().getY()] == Settings::SYMBOL_SPACE) {
                        this->monsters[i].setX(this->monsters[i].getPosition().getX() + 1);
                        break;
                    }
            }
        }
    }
    
    this->printMap();
    
    if (this->player.getEnergy() <= 0) {
        this->end();
    }
}

// Open the door after collecting the gem
void Game::openDoor() {
    this->map->getTable(true);
}

// Go to the next level
void Game::levelUp() {
    
    this->level += 1;
    
    this->logger.add("Entered level " + to_string(this->level));
    
    // Changing the map
    for (int i = 0; i < this->map->getHeight(); i++) {
        delete [] this->renderedMap[i];
    }
    delete [] this->renderedMap;
    
    delete this->map;
    this->map = new Map(this->level);
    
    this->renderedMap = new char*[this->map->getHeight()];
    for (int i = 0; i < this->map->getHeight(); i++) {
        this->renderedMap[i] = new char[this->map->getWidth()];
    }
    
    // Defining the new positions of the objects
    this->spawnObjects();
}

// Ends the game
void Game::end() {
    if (this->player.getEnergy() > 0) {
        this->logger.add("Safely left the dungeon");
        cout << "You safely left the dungeon" << endl;
    } else {
        this->logger.add("Lost ");
        cout << "You lost" << endl;
    }
    this->isRunning = false;
}
