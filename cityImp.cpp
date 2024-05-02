// Programmers: Gavin Sutherland and Jason Ni
// Date: 05/01/2024
// File: cityImp.cpp
// Purpose: Contains the CIty class implementation

#include "city.h"
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
        for (int j = 0; j < 13; ++j) {
            cout << cityGrid[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

Point City::getUniquePosition() const {
    // Get a random position that is not occupied
    int row = rand() % 11;
    int col = rand() % 13;
    while (cityGrid[row][col]!= ' ') {
        row = rand() % 11;
        col = rand() % 13;
    }

    Point point;
    point.col = col;
    point.row = row;

    return point;
}