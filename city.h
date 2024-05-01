// Programmers: Gavin Sutherland and Jason Ni
// Date: 04/25/2024
// File: city.h
// Purpose: Contains the City class for the police chase program

#ifndef CITY_H
#define CITY_H

#include <iostream>
#include <string>

using namespace std;

class City {
    public:
        // Constructors
        City();

        // Getters
        char getValueAtCoordinate(int x, int y) { return cityGrid[x][y];}
        int getNumJewels() { return numJewels;}

        // Setters
        void setValueAtCoordinate(char value, int x, int y) { cityGrid[x][y] = value;}

        void printGrid();

    private:
        char cityGrid[11][13];
        int numJewels;
};

#endif