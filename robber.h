// Programmers: Gavin Sutherland and Jason
// Date: 04/25/2024
// File: robber.h
// Purpose: Contains the Robber class for the police chase program

#ifndef ROBBER_H
#define ROBBER_H

#include <iostream>
#include <string>
#include "jewel.h"

using namespace std;

class Robber {
    private:
        int id;
        int xPos, yPos;
        Jewel bag[20];
        static int valueOfJewels;
        bool isActive;
        bool isGreedy;
    public:
        // Constructors
        // Copy
        Robber(const Robber& other);

        // Desc: Picks up a piece of loot and adds it to the robbers bag
        // Pre:  None
        // Post: Adds the loot to the bag
        void pickUpLoot(Jewel jewel);

        // Desc: Overloads the -- operator to remove on item from the robber's bag
        // Pre:  None
        // Post: The last item in the bag is removed 
        Robber operator --();

        // Desc: Moves the robber one step in a direction
        // Pre:  None
        // Post: The robber moves to a new position and updates their position variables
};

#endif