// Programmers: Gavin Sutherland (gas2bt, 101) and Jason Ni (Jnwkb, 301)
// Date: 04/25/2024
// File: jewel.h
// Purpose: Contains the Jewel class for the police chase program

#ifndef JEWEL_H
#define JEWEL_H

#include <iostream>
#include <string>

using namespace std;

class Jewel
{
    public:
        // Constructors
        Jewel() {};
        Jewel(int row, int col) : row(row), col(col), value((row+col)*(row+col)) {}

        // Getters
        int getValue() const {return value;};
        int getRow() const {return row;};
        int getCol() const {return col;};
        int isPickedUp() const { return pickedUp; }

        // Setters
        void setPickedUp(bool isPickedUp) { pickedUp = isPickedUp; }
        void setNewLocation(int newRow, int newCol) {
            row = newRow;
            col = newCol;
        }

        // Member functions
        Jewel operator * (const int multiplier);
        Jewel operator *= (const int multiplier);

    private:
        // Members
        int value;
        int row;
        int col;
        int pickedUp = false;
};


#endif