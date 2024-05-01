// Programmers: Gavin Sutherland and Jason Ni
// Date: 05/01/2024
// File: police.h
// Purpose: Contains the police class for the police chase program

#ifndef POLICE_H
#define POLICE_H

#include <iostream>
#include <string>
#include "robber.h"

using namespace std;

class Police {
private:
    int id;
    int currentRow;
    int currentCol;
    int totalConfiscatedLoot;
    int totalRobbersCaught;

public:
    // Constructor
    Police(int id, int currentRow, int currentCol) : id(id), currentRow(currentRow), currentCol(currentCol), totalConfiscatedLoot(0), totalRobbersCaught(0) {}

    // Function to arrest a robber
    // void arrest(Robber& robber); // TODO cry about it

    // Function to move the police
    void move();

    // Getter methods
    int getCurrentRow() const {return currentRow;}
    int getCurrentCol() const {return currentCol;}
    int getTotalConfiscatedLoot() const {return totalConfiscatedLoot;}
    int getTotalRobbersCaught() const {return totalRobbersCaught;}
};


#endif