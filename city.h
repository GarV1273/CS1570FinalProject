// Programmers: Gavin Sutherland and Jason Ni
// Date: 04/25/2024
// File: city.h
// Purpose: Contains the City class for the police chase program

#ifndef CITY_H
#define CITY_H

#include <iostream>
#include <string>
#include "robber.h"
#include "police.h"
#include "jewel.h"

using namespace std;

// Used to return a unique point to the main function
struct Point {
    int row;
    int col;
};

class City {
    public:
        // Constructors
        City();

        // Getters
        char getValueAtCoordinate(int row, int col) { return cityGrid[row][col];}
        int getNumJewels() { return numJewels;}

        // Setters
        void setValueAtCoordinate(char value, int row, int col) { cityGrid[row][col] = value;}

        void printGrid();

        Point getUniquePosition() const;

        template <typename T>
        void updateBoard(Jewel jewels[60], Police police[3], Robber<T> robbers[20]);

    private:
        char cityGrid[11][13];
        int numJewels = 60;
};

#endif