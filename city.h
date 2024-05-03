// Programmers: Gavin Sutherland and Jason Ni
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

using namespace std;

// Used to return a unique point to the main function
struct Point {
    int row;
    int col;
};

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

        Point getUniquePosition() const;

        template <typename T>
        void updateBoard(Jewel jewels[60], Police police[3], Robber<T> robbers[20], int numRobbers) {
            // Put jewels on the board
            for (int i = 0; i < 60; i++) {
                setValueAtCoordinate('J', jewels[i].getRow(), jewels[i].getCol());
            }

            // Put robbers on the board
            for (int i = 0; i < numRobbers; i++) {
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

    private:
        char cityGrid[11][13];
        int numJewels = 60;
};

#endif