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

    // Desc: Function to arrest a robber
    // Pre: None
    // Post: Arrest a single robber
    template <class T>
    void singleArrest(Robber<T>& robber);

    // Desc: Function to arrest a group of robber
    // Pre: None
    // Post: Arrest all the robbers in the same cell
    template <class T>
    void multiArrest(Robber<T> robber[20]);

    // Desc: Function to move the police
    // Pre: None
    // Post: Move the police to a legal cell
    void move();

    // Getter methods
    int getRow() const {return currentRow;}
    int getCol() const {return currentCol;}
    int getTotalConfiscatedLoot() const {return totalConfiscatedLoot;}
    int getTotalRobbersCaught() const {return totalRobbersCaught;}
};


#endif