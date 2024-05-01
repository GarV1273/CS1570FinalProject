// Programmers: Gavin Sutherland and Jason Ni
// Date: 05/01/2024
// File: policeImp.cpp
// Purpose: Police class implementation

#include "police.h"

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