//
//  Logger.hpp
//  Final project (Treasure Hunting Game)
//  TAMK, Programming Languages 2, 20i260E
//  Created by Sviatoslav Vasev on 16.4.2021.
//

#pragma once
#include <iostream>
#include <time.h>
#include <vector>
using namespace std;

class Logger {
private:
    
    // Stores all the events with timestamps as strings
    vector<string> logs;
    
public:
    
    // Adds a new event
    void add(string);
    
    // Prints all the events
    void print();
};
