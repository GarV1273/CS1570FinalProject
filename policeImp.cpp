// Programmers: Gavin Sutherland and Jason Ni
// Date: 05/01/2024
// File: policeImp.cpp
// Purpose: Police class implementation

#include <iostream>

#include "police.h"

using namespace std;

void Police::move() {
    // Implement movement logic here
    int direction = rand() % 8;

    bool directionIsValid = false;

    // Get a valid direction
    while (!directionIsValid) {
        switch(direction) {
            case 0:
                if (currentRow > 0 && currentCol > 0) { // Move is valid
                    directionIsValid = true;
                    currentRow--;
                    currentCol--;
                }
                break;
            case 1:
                if (currentCol > 0) { // Move is valid
                    directionIsValid = true;
                    currentRow--;
                }
                break;

            case 2: 
                if (currentRow < 10 && currentCol > 0) { // Move is valid
                    directionIsValid = true;
                    currentRow--;
                    currentCol++;
                }
                break;

            case 3:
                if(currentCol > 0) { // Move is valid
                    directionIsValid = true;
                    currentCol--;
                }
                break;

            case 4:
                if(currentCol < 12) { // Move is valid
                    directionIsValid = true;
                    currentCol++;
                }
                break;

            case 5:
                if(currentRow < 10 && currentCol > 0) { // Move is valid
                    directionIsValid = true;
                    currentRow++;
                    currentCol--;
                }
                break;

            case 6:
                if (currentRow < 10) { // Move is valid
                    directionIsValid = true;
                    currentRow++;
                }
                break;

            case 7:
                if (currentRow < 10 && currentCol < 12) { // Move is valid
                    directionIsValid = true;
                    currentRow++;
                    currentCol++;
                }
                break;
                
            default:
                // This should never happen 
                cout << "Error with random direction.";
        }
    }
}

template <class T>
void Police::singleArrest(Robber<T>& robber) {
    // Set robber to inactive state
    robber.isActive = false;

    // Take the loot from the robber, double the value, and add to the total confiscated loot
    for (int i = 0; i < robber.itemsInBag; i++) {
        robber.loot[i] = robber.loot[i] * 2;
        totalConfiscatedLoot += robber.loot[i];
    }
}

template <class T>
void Police::multiArrest(Robber<T> robber[20]) {
    // Check if the robber is active and on the current spot
    for (int i = 0; i < 20; i++) {
        if (robber[i].isActive && robber[i].currentRow == currentRow && robber[i].currentCol == currentCol) {
            // Double their loot using *= and add total
            robber[i].loot *= 2;
            totalConfiscatedLoot += robber[i].loot;
            robber[i].isActive = false;
        }
    }
}