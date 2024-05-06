// Programmers: Gavin Sutherland (gas2bt, 101) and Jason Ni (Jnwkb, 301)
// Date: 05/01/2024
// File: policeImp.cpp
// Purpose: Police class implementation

#include <iostream>

#include "police.h"

using namespace std;

void Police::move() {
    // Implement movement logic here
    bool directionIsValid = false;

    // Get a valid direction
    while (!directionIsValid) {
        int direction = rand() % 8;
        switch(direction) {
            case 0:
                if (currentRow > 0 && currentCol > 0) { // Move is valid
                    directionIsValid = true;
                    currentRow--;
                    currentCol--;
                }
                break;
            case 1:
                if (currentRow > 0) { // Move is valid
                    directionIsValid = true;
                    currentRow--;
                }
                break;

            case 2: 
                if (currentRow > 0 && currentCol < 12) { // Move is valid
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
                break;
        }
    }
}

