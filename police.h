// Programmers: Gavin Sutherland (gas2bt, 101) and Jason Ni (Jnwkb, 301)
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
    void arrest(Robber<T>& robber, bool multiArrest) {
        // Set robber to inactive state
        robber.isActive = false;
        totalRobbersCaught++;

        // Take the loot from the robber, double the value, and add to the total confiscated loot
        for (int i = 0; i < robber.itemsInBag; i++) {
            cout << "Taking loot #" << i << endl;
            if (multiArrest) {
                // Use *=
                robber.bag[i] *= 2;
            } else {
                // Use *
                robber.bag[i] = robber.bag[i] * 2;
            }

            cout << "Loot value: "<<robber.bag[i].getValue() << endl;
            
            totalConfiscatedLoot += robber.bag[i].getValue();
        }
    }

    // Desc: Function to move the police
    // Pre: None
    // Post: Move the police to a legal cell
    void move();

    // Getter methods
    int getID() const { return id; }
    int getRow() const {return currentRow;}
    int getCol() const {return currentCol;}
    int getTotalConfiscatedLoot() const {return totalConfiscatedLoot;}
    void setTotalConfiscatedLoot(int newValue) { totalConfiscatedLoot = newValue; }
    int getTotalRobbersCaught() const {return totalRobbersCaught;}
};


#endif