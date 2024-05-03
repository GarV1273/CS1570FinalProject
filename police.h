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
    int totalConfiscatedLoot = 0;
    int totalRobbersCaught = 0;

public:
    // Constructor
    Police() {}
    Police(int id, int currentRow, int currentCol) : id(id), currentRow(currentRow), currentCol(currentCol), totalConfiscatedLoot(0), totalRobbersCaught(0) {}

    // Function to arrest a robber
    template <class T>
    void singleArrest(Robber<T>& robber);

    template <class T>
    void multiArrest(Robber<T> robber[20]);

    // Function to move the police
    void move();

    // Getter methods
    int getRow() const {return currentRow;}
    int getCol() const {return currentCol;}
    int getTotalConfiscatedLoot() const {return totalConfiscatedLoot;}
    int getTotalRobbersCaught() const {return totalRobbersCaught;}
};


#endif