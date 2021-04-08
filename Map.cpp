//
//  map.cpp
//  Final project (Treasure Hunting Game)
//  TAMK, Programming Languages 2, 20i260E
//  Created by Sviatoslav Vasev on 16.2.2021.
//

#include "Map.hpp"
using namespace std;

// Changes one character to the passed value
void Map::set(int width, int height, GameObject * obj) {
    if (this->table[height * this->width + width] == nullptr or this->table[height * this->width + width] == NULL) {
        this->table[height * this->width + width] = obj;
    } else {
        delete this->table[height * this->width + width];
        this->table[height * this->width + width] = obj;
    }
}

// Constructor
Map::Map (int level, Player * player) {
    
    // Create the size of the map according to the level
    this->width = level + 7;
    this->height = level + 7;
    
    // Dynamically allocated array
    this->table = new GameObject*[width * height];
    
    // Assigning every inner char SYMBOL_SPACE and outer har SYMBOL_WALL
    for (int h = 0; h < height; h++) {
        for (int w = 0; w < width; w++) {
            if (h == 0 or h == height - 1 or w == 0 or w == width - 1) {
                Wall * obj = new Wall(w, h);
                this->set(w, h, obj);
            } else {
                Space * obj = new Space(w, h);
                this->set(w, h, obj);
            }
        }
    }
    
    // Adding internal walls
    srand(int(time(NULL)));
    for (int i = 0; i < (width - 2) * (height - 2) / 5; i++) {
        int w = rand() % (width - 2) + 1;
        int h = rand() % (height - 2) + 1;
        
        Wall * obj = new Wall(w, h);
        this->set(w, h, obj);
    }
    
    // Adding the player
    for (int w = this->width / 2; w < this->width; w++) {
        for (int h = this->height / 2; h < this->height; h++) {
            if(this->getElementAt(w, h).getType() == SpaceType) {
                player->setX(w);
                player->setY(h);
                this->set(w, h, player);
                goto playerAdded;
            }
        }
    }
    playerAdded:
    
    if (false) {
        
    }
}

// Destructor
Map::~Map () {
    // Delete allocated memory
    for (int i = 0; i < this->width * this->height; i++) {
        delete this->table[i];
    }
    delete [] this->table;
}

// Copy constructor
Map::Map (const Map &right) {
    this->width = right.width;
    this->height = right.height;
    this->table = new GameObject*[width * height];
    for (int i = 0; i < this->width * this->height; i++) {
        this->table[i] = right.table[i];
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
    this->table = new GameObject*[width * height];
    for (int i = 0; i < width * height; i++) {
        this->table[i] = right.table[i];
    }
    return *this;
}

// Prints the table
void Map::print() const {
    for (int h = 0; h < this->height; h++) {
        for (int w = 0; w < this->width; w++) {
            cout << this->getElementAt(w, h).getSymbol();
        }
        cout << endl;
    }
}

// Moves the entity
void Map::moveObject(GameObject &obj, char direction) {
    if (obj.getType() != PlayerType or obj.getType() != MonsterType) return;
    switch (direction) {
        case 'w':
            if (this->getElementAt(obj.getX(), obj.getY() - 1).getType() != SpaceType) return;
            swap(this->table[obj.getY() * this->width + obj.getX()], this->table[(obj.getY() - 1) * this->width + obj.getX()]);
            cout << "done" << endl;
            break;
    }
}

// Returns the element at the given coordinates
GameObject &Map::getElementAt(int x, int y) const {
    return *this->table[y * this->width + x];
}

// Returns the element at the given position
GameObject &Map::getElementAt(Position pos) const {
    return this->getElementAt(pos.getX(), pos.getY());
}

// Returns the player
GameObject &Map::getPlayer() const {
    for (int i = 0; i < this->width * this->height; i++) {
        if (this->table[i]->getType() == PlayerType) {
            return *this->table[i];
        }
    }
    return *this->table[0];
}
