// Programmers: Gavin Sutherland (gas2bt, 101) and Jason Ni (Jnwkb, 301)
// Date: 04/25/2024
// File: robber.h
// Purpose: Contains the Robber class for the police chase program

#ifndef ROBBER_H
#define ROBBER_H

#include <iostream>
#include <string>

using namespace std;

template <class T>
class Robber {
    private:
        int id;
        int currentRow, currentCol;
        T bag[20];
        int itemsInBag = 0;
        bool isActive;
        bool isGreedy;
        bool hasSpawnedOtherRobber = false;
        int turnsSinceLastJewel = 0;
        int turnsLeftImmobilized = 0;
    public:
        static int valueOfJewels;

        // Constructors
        // Default
        Robber() {};

        // Parameterized
        Robber(int id, int currentRow, int currentCol, bool isActive, bool isGreedy)
            : id(id), currentRow(currentRow), currentCol(currentCol), 
            isActive(isActive), isGreedy(isGreedy) {}

        // Copy
        Robber(Robber& other);

        // Member functions

        // Desc: Picks up a piece of loot and adds it to the robbers bag
        // Pre:  None
        // Post: Adds the loot to the bag
        void pickUpLoot(T loot);

        // Desc: Overloads the -- operator to remove on item from the robber's bag
        // Pre:  None
        // Post: The last item in the bag is removed 
        Robber& operator--();

        // Desc: Moves the robber one step in a direction
        // Pre:  None
        // Post: The robber moves to a new position and updates their position variables
        void move();


        // Desc: Gets the numeric value of the loot in the robbers bag
        // Pre: None
        // Post: The value is retured
        int getValueOfLootInBag();

        // Getters/setters
        int getID() const { return id; }
        int getRow() const { return currentRow; }
        int getCol() const { return currentCol; }
        int getNumItemsInBag() { return itemsInBag; }
        bool getHasSpawnedOtherRobber() { return hasSpawnedOtherRobber; }
        void disableRobberSpawning() { hasSpawnedOtherRobber = true; }
        void incrementItemsInBag();
        void decrementItemsInBag();
        void resetBag();
        bool robberIsActive() { return isActive; }
        bool robberIsGreedy() { return isGreedy; }
        int getTurnsWithoutJewel() { return turnsSinceLastJewel; }
        int getTurnsLeftImmobilized() { return turnsLeftImmobilized; }
        void incrementTurnsWithoutJewel() { turnsSinceLastJewel++; }
        void immobilize() { turnsLeftImmobilized = 2; }
        void decrementImmobilizeCounter() { turnsLeftImmobilized--; }
        void resetImmobilizeCounter() { turnsSinceLastJewel = 0; }
        int getRowOfLastItem() { return bag[itemsInBag-1].getRow(); }
        int getColOfLastItem() { return bag[itemsInBag-1].getCol(); }

        // Friend classes
        friend class Police;
};

#include "robberImp.hpp"
#endif