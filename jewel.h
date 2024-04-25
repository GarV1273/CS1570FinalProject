// Programmers: Gavin Sutherland and Jason
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
        Jewel(const int value, const int xPos, const int yPos);

        // Getters
        int getValue() const;
        int getXPos() const;
        int getYPos() const;

        // Member functions
        Jewel operator * (const Jewel& jewel);
        Jewel operator *= (const Jewel& jewel);

    private:
        // Members
        const int value;
        const int xPos;
        const int yPos;
};


#endif