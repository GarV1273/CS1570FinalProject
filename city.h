// Programmers: Gavin Sutherland and Jason
// Date: 04/25/2024
// File: city.h
// Purpose: Contains the City class for the police chase program

#ifndef CITY_H
#define CITY_H

#include <iostream>
#include <string>

class City {
    public:
        // Constructors
        City(){ numJewels = 60;};

        char cityGrid[11][13];
        int numJewels;
};

#endif