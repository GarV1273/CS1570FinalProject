// Programmers: Gavin Sutherland (gas2bt, 101) and Jason Ni (Jnwkb, 301)
// Date: 04/25/2024
// File: city.h
// Purpose: Contains the City class for the police chase program

#ifndef CITY_H
#define CITY_H

#include <iostream>
#include <string>
#include "robber.h"
#include "police.h"
#include "jewel.h"
#include "header.h"

using namespace std;

class City {
    public:
        // Constructors
        City();

        // Getters
        char getValueAtCoordinate(int row, int col) { return cityGrid[row][col];}
        int getNumJewels() { return numJewels;}

        // Setters
        void setValueAtCoordinate(char value, int row, int col) { cityGrid[row][col] = value;}

        // Desc: Print out the game board
        // Pre: None
        // Post: Output the current board layout
        void printGrid();

        // Desc: Gets a random, empty position from the board
        // Pre:  0 <= row < 11, 0 <= col < 13
        // Post: Returns a point struct with a unique coordinate
        Point getUniquePosition() const;

        // Desc: Resets the board to the initial state (empty)
        // Pre:  None
        // Post: The cityGrid member is reset
        void resetBoard();

        // Desc: Finds an open spot adjecent to a given position
        // Pre:  0 <= row < 11, 0 <= col < 13
        // Post: Returns a point struct with an open spot
        Point getOpenSpotNearPosition(int row, int col);

        // Desc: Resets and remakes the board using the coordinate data from the three lists
        // Pre:  All elements of jewels, police, and robbers w/ index < numRobbers are assumed to be defined
        // Post: Updates the cityGrid member variable
        template <typename T>
        void updateBoard(Jewel jewels[60], Police police[3], Robber<T> robbers[20], int numRobbers) {
            // Reset the old board
            resetBoard();

            // Put jewels on the board
            for (int i = 0; i < 60; i++) {
                if (!jewels[i].isPickedUp()) {
                    setValueAtCoordinate('J', jewels[i].getRow(), jewels[i].getCol());
                } 
            }

            // Put robbers on the board
            for (int i = 0; i < numRobbers; i++) {
                // Check if a robber is already in a spot, if so, notate with 'R'
                if (getValueAtCoordinate(robbers[i].getRow(), robbers[i].getCol()) == 'r') {
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

    private:
        char cityGrid[11][13];
        int numJewels = 60;
};

#endif