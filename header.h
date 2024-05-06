// Programmers: Gavin Sutherland (gas2bt, 101) and Jason Ni (Jnwkb, 301)
// Date: 05/03/2024
// File: header.h
// Purpose: Header file for global functions

#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include "jewel.h"
#include "police.h"

using namespace std;

// Used to return a unique point to the main function
struct Point {
    int row;
    int col;
};

// Desc: Generates a unique ID for an object to use
// Pre:  None
// Post: Returns an iteger ID. Always unique.
int getUniqueID();

int getIndexOfJewelAtPosition(Jewel jewels[60], int row, int col);

// Desc: This gets the index of an officer in the array of officers at the given row and column
// Pre:  The row and column are assumed to point to an officer
// Post: The index of the officer is returned
// Note: For use in two officers running into eachother, use the getIndexOfOfficerAtPositionAsOfficer function
int getIndexOfOfficerAtPosition(Police police[3], int row, int col);

// Desc: This gets the index of an officer in the array of officers at the given row and column
// THIS VERSION SHOULD BE USED WHEN AN OFFICER IS ASKING FOR THE POSITION OF ANOTHER OFFICER TO AVOID RETURNING THE WRONG ONE
// Pre: The row and column are assumed to have an officer there
// Post: The correct officer is returned
int getIndexOfOfficerAtPositionAsOfficer(Police police[3], int row, int col, int askerIndex);

// Desc: Gets the index of a robber at a certain position (row, column)
// Pre:  A robber is assumed to exist at that position
// Post: The index where the robber can be found is returned
template <class T>
int getIndexOfRobberAtPosition(Robber<T> robbers[20], int numRobbers, int row, int col) {
    for (int i = 0; i < numRobbers; i++) {
        if (robbers[i].getRow() == row && robbers[i].getCol() == col) {
            return i;
        }
    }

    // This should never happen. It's included to stop error messages
    cout << "ERROR IN Robber FINDING FUCNTION" << endl;
    return -1;
}

#endif