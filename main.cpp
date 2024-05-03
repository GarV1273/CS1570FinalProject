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
#include "header.h"

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
        Jewel newJewel = Jewel(0, uniquePoint.row, uniquePoint.col);
        jewels[i] = newJewel;
    }

    // List of Robbers
    Robber<Jewel> robbers[20];

    // Normal Robbers
    for (int i = 0; i < 2; i++) {
        Point uniquePoint = city.getUniquePosition();
        Robber<Jewel> newRobber = Robber<Jewel>(getUniqueID(), uniquePoint.row, uniquePoint.col, true, false);
        robbers[i] = newRobber;
    }

    //Greedy Robbers
    for (int i = 0; i < 2; i++) {
        Point uniquePoint = city.getUniquePosition();
        Robber<Jewel> newRobber = Robber<Jewel>(getUniqueID(), uniquePoint.row, uniquePoint.col, true, true);
        robbers[i + 2] = newRobber;
    }

    // List of Police
    Police police[3];

    // Get their coordinates
    for (int i = 0; i < 3; i++) {
        Point uniquePoint = city.getUniquePosition();
        Police newPolice = Police(getUniqueID(), uniquePoint.row, uniquePoint.col);
        police[i] = newPolice;
    }

    // Update/Print City Board
    city.updateBoard<Jewel>(jewels, police, robbers);
    city.printGrid();

    return 0;
}