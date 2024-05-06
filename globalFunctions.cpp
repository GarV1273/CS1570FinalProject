// Programmers: Gavin Sutherland (gas2bt, 101) and Jason Ni (Jnwkb, 301)
// Date: 05/05/2024
// File: globalfunctions.cpp
// Purpose: Contains all of the global level functions for the main program

#include "header.h"
#include "jewel.h"
#include "police.h"

int getUniqueID() {
    static int id = 0;
    return ++id;
}

int getIndexOfJewelAtPosition(Jewel jewels[60], int row, int col) {
    for (int i = 0; i < 60; i++) {
        if (jewels[i].getRow() == row && jewels[i].getCol() == col) {
            return i;
        }
    }

    // This should never happen. It's included to stop error messages
    cout << "There is no jewel at this location" << endl;
    return -1;
}

int getIndexOfOfficerAtPosition(Police police[3], int row, int col) {
    for (int i = 0; i < 3; i++) {
        if (police[i].getRow() == row && police[i].getCol() == col) {
            return i;
        }
    }

    // This should never happen. It's included to stop error messages
    cout << "ERROR IN Police FINDING FUCNTION" << endl;
    return -1;
}

int getIndexOfOfficerAtPositionAsOfficer(Police police[3], int row, int col, int askerIndex) {
    for (int i = 0; i < 3; i++) {
        if (police[i].getRow() == row && police[i].getCol() == col && askerIndex != i) {
            return i;
        }
    }

    // This should never happen. It's included to stop error messages
    cout << "ERROR IN Police FINDING FUCNTION" << endl;
    return -1;
}
