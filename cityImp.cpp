// Programmers: Gavin Sutherland and Jason Ni
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

template <typename T>
void City::updateBoard(Jewel jewels[60], Police police[3], Robber<T> robbers[20]) {
    // Put jewels on the board
    for (int i = 0; i < 60; i++) {
        setValueAtCoordinate('J', jewels[i].getRow(), jewels[i].getCol());
    }

    // Put robbers on the board
    for (int i = 0; i < 20; i++) {
        // Check if a robber is already in a spot, if so, notate with 'R'
        if (getValueAtCoordinate(robbers[i].getRow(), robbers[i].getCol())) {
            setValueAtCoordinate('R', robbers[i].getRow(), robbers[i].getCol());
        } else {
            // Single robber
            // Check if they are active
            if (robbers[i].robberIsActive()) {
                setValueAtCoordinate('r', robbers[i].getRow(), robbers[i].getCol());
            } else {
                setValueAtCoordinate('A', robbers[i].getRow(), robbers[i].getCol());
            }
        }
    }

    // Put police on the board
    for (int i = 0; i < 3; i++) {
        setValueAtCoordinate('P', police[i].getRow(), police[i].getCol());
    }

}