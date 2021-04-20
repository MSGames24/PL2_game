//
//  Logger.cpp
//  Final project (Treasure Hunting Game)
//  TAMK, Programming Languages 2, 20i260E
//  Created by Sviatoslav Vasev on 16.4.2021.
//

#include "Logger.hpp"

// Adds a new event
void Logger::add(string event) {
    time_t current_time = time(NULL);
    string time_str = ctime(&current_time);
    this->logs.push_back(time_str.substr(0, 24) + " - " + event);
}

// Prints all the events
void Logger::print() {
    for (int i = 0; i < this->logs.size(); i++) {
        cout << this->logs[i] << endl;
    }
}
