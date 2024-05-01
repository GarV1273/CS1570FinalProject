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
        Jewel::Jewel(int value, int xPos, int yPos) 
            : value(value), xPos(xPos), yPos(yPos) {}

        // Getters
        int getValue() const {return value;};
        int getXPos() const {return xPos;};
        int getYPos() const {return yPos;};

        // Member functions
        Jewel operator * ();
        // Jewel operator *= (const Jewel& jewel); // TODO Implement

    private:
        // Members
        const int value;
        const int xPos;
        const int yPos;
};


#endif