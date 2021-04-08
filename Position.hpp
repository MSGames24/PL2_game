//
//  Position.hpp
//  Assignment 5 (A05_4)
//  TAMK, Programming Languages 2, 20i260E
//  Created by Sviatoslav Vasev on 16.2.2021.
//

#pragma once

class Position {
private:
    // X coordinate
    int x;
    
    // Y coordinate
    int y;
    
public:
    // Constructor
    Position (int, int);
    
    // Constructor
    Position ();
    
    // Operator ==
    bool operator== (const Position &);
    
    // Operator ==
    bool operator!= (const Position &);
    
    // Set the position when two coordinates given
    void set (int, int);
    
    // Set the positin when x coordinate given
    void setX (int);
    
    // Set the position when y coordinate given
    void setY (int);
    
    // Returns the x coordinate
    int getX () const;
    
    // Returns the y coordinate
    int getY () const;
};
