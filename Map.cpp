//
//  map.cpp
//  Final project (Treasure Hunting Game)
//  TAMK, Programming Languages 2, 20i260E
//  Created by Sviatoslav Vasev on 16.2.2021.
//

#include "Map.hpp"
using namespace std;

// Constructor
Map::Map (int level) {
    
    // Create the size of the map according to the level
    this->width = level + 7;
    this->height = level + 7;
    
    // Dynamically allocated 2D array
    this->table = new char*[height];
    for (int i = 0; i < this->height; i++) {
        this->table[i] = new char[this->width];
    }
    
    // Assigning every inner char SYMBOL_SPACE and outer har SYMBOL_WALL
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (y == 0 or y == height - 1 or x == 0 or x == width - 1) {
                this->table[x][y] = Settings::SYMBOL_WALL;
            } else {
                this->table[x][y] = Settings::SYMBOL_SPACE;
            }
        }
    }
    
    // Adding internal walls
    srand(int(time(NULL))); 
    for (int i = 0; i < Settings::FORMULA_WALLS(this->width, this->height); i++) {
        int x = rand() % (width - 2) + 1;
        int y = rand() % (height - 2) + 1;
        
        this->table[x][y] = Settings::SYMBOL_WALL;
    }
    
    // Generating the door to the next level
    int x = 0;
    int y = 0;
    switch (rand() % 4) {
        case 0:
            x = 0;
            y = rand() % this->height;
            while (this->table[1][y] == Settings::SYMBOL_WALL) {
                y = rand() % this->height;
            }
            break;
        case 1:
            x = rand() % this->width;
            y = 0;
            while (this->table[x][1] == Settings::SYMBOL_WALL) {
                x = rand() % this->width;
            }
            break;
        case 2:
            x = this->width - 1;
            y = rand() % this->height;
            while (this->table[x-1][y]) {
                y = rand() % this->height;
            }
            break;
        case 3:
            x = rand() % this->width;
            y =  this->height - 1;
            while (this->table[x][y-1]) {
                x = rand() % this->width;
            }
            break;
    }
    this->doorPosition.set(x, y);
}

// Destructor
Map::~Map () {
    // Delete allocated memory
    for (int i = 0; i < this->height; i++) {
        delete [] this->table[i];
    }
    delete [] this->table;
}

// Copy constructor
Map::Map (const Map &right) {
    this->width = right.width;
    this->height = right.height;
    this->table = new char*[height];
    for (int i = 0; i < this->height; i++) {
        this->table[i] = new char[this->width];
        for (int k = 0; k < this->width; k++) {
            this->table[i][k] = right.table[i][k];
        }
    }
}

// Assignment operator
Map& Map::operator= (const Map &right) {
    if (this == &right) {
        return *this;
    }
    this->~Map();
    this->width = right.width;
    this->height = right.height;
    this->table = new char*[width * height];
    for (int i = 0; i < width * height; i++) {
        this->table[i] = right.table[i];
    }
    return *this;
}

// Prints the table
char ** Map::getTable(bool isEaten) const {
    if (isEaten) {
        this->table[doorPosition.getX()][doorPosition.getY()] = Settings::SYMBOL_DOOR;
    }
    return this->table;
}

// Returns the width
int Map::getWidth() {
    return this->width;
}

// Returns the height
int Map::getHeight() {
    return this->height;
}
