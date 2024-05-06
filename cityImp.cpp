// Programmers: Gavin Sutherland (gas2bt, 101) and Jason Ni (Jnwkb, 301)
// Date: 05/01/2024
// File: cityImp.cpp
// Purpose: Contains the CIty class implementation

#include <iostream>

#include "city.h"
#include "jewel.h"
#include "robber.h"

City::City() {
    // Initialize grid with empty spaces
    for (int i = 0; i < 11; ++i) {
        for (int j = 0; j < 13; ++j) {
            cityGrid[i][j] = ' ';
        }
    }

    // Initialize jewel count
    numJewels = 0;
}

void City::printGrid() {
    // Print grid
    for (int i = 0; i < 11; ++i) {
        cout << "|";
        for (int j = 0; j < 13; ++j) {
            cout << cityGrid[i][j] << "|";
        }
        cout << endl << "---------------------------" << endl;
    }
    cout << endl;
}

Point City::getUniquePosition() const {
    // Get a random position that is not occupied
    int row = rand() % 11;
    int col = rand() % 13;
    while (cityGrid[row][col] != ' ') {
        row = rand() % 11;
        col = rand() % 13;
    }

    Point point;
    point.col = col;
    point.row = row;

    return point;
}

void City::resetBoard() {
    for (int i = 0; i < 11; ++i) {
        for (int j = 0; j < 13; ++j) {
            cityGrid[i][j] = ' ';
        }
    }

    return;
}

Point City::getOpenSpotNearPosition(int row, int col) {
    Point point;
    // Check up-left
    if (row > 0 && col > 0) { 
        if (cityGrid[row-1][col-1] == ' ') {
            point.row = row-1;
            point.col = col-1;
            return point;
        }
    }

    // Check up
    if (row > 0) { 
        if (cityGrid[row-1][col] == ' ') {
            point.row = row-1;
            point.col = col;
            return point;
        }
    }
    
    // Check up-right
    if (row > 0 && col < 12) { 
        if (cityGrid[row-1][col+1] == ' ') {
            point.row = row-1;
            point.col = col+1;
            return point;
        }
    }

    // Left
    if (col > 0) { 
        if (cityGrid[row][col-1] == ' ') {
            point.row = row;
            point.col = col-1;
            return point;
        }
    }

    // Right
    if (col < 12) { 
        if (cityGrid[row][col+1] == ' ') {
            point.row = row;
            point.col = col+1;
            return point;
        }
    }

    // Down-left
    if (row < 10 && col > 0) { 
        if (cityGrid[row+1][col-1] == ' ') {
            point.row = row+1;
            point.col = col-1;
            return point;
        }
    }

    // Down
    if (row < 10) { 
        if (cityGrid[row+1][col] == ' ') {
            point.row = row+1;
            point.col = col;
            return point;
        }
    }

    // Down-right
    if (row < 10 && col < 12) { 
        if (cityGrid[row+1][col+1] == ' ') {
            point.row = row+1;
            point.col = col+1;
            return point;
        }
    }

    // If no point works, return an error point
    point.row = -1;
    point.col = -1;
    return point;
}