// Programmers: Gavin Sutherland and Jason Ni
// Date: 05/02/2024
// File: jewel.h
// Purpose: Main logic 

#include <iostream>
#include <cstdlib>

#include "city.h"
#include "jewel.h"
#include "robber.h"
#include "police.h"

using namespace std;

int main() {
    // Set seed to 100
    srand(100);

    // Initialize the city object
    City city;

    // Create the list of jewels
    Jewel jewels[60];
    
    // Get the random coordinates for the jewels. Each on should be unique.
    for (int i = 0; i < 60; i++) {
        // Get unique coordinate
        Point uniquePoint = city.getUniquePosition();
        Jewel jewel();
    }


    // List of Robbers


    // Get their coordinates
    Robber robbers[4];
    // Normal Robbers
    for (int i = 0; i < 2; i++) {
        Point uniquePoint = city.getUniquePosition();
    }

    //Greedy Robbers
    for (int i = 0; i < 2; i++) {
        Point uniquePoint = city.getUniquePosition();
    }

    // List of Police

    // Get their coordinates
    for (int i = 0; i < 3; i++) {
        Point uniquePoint = city.getUniquePosition();
    }

    // Print City Board
    city.printGrid();

    return 0;
}