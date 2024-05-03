// Programmers: Gavin Sutherland and Jason Ni
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
        Jewel(int value, int row, int col) : value(value), row(row), col(col) {}

        // Getters
        int getValue() const {return value;};
        int getRow() const {return row;};
        int getCol() const {return col;};

        // Member functions
        Jewel operator * (const int multiplier);
        Jewel operator *= (const int multiplier);

    private:
        // Members
        int value;
        int row;
        int col;
};


#endif