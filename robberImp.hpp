// Programmers: Gavin Sutherland (gas2bt, 101) and Jason Ni (Jnwkb, 301)
// Date: 04/25/2024
// File: robberImp.hpp
// Purpose: Implementation for the Robber class (found in robber.h)

#include <iostream>

using namespace std;

template <class T>
int Robber<T>::valueOfJewels {0};

// Copy constructor overload
template <class T>
Robber<T>::Robber(Robber& other) {
    other.hasSpawnedOtherRobber = true;
    id = other.id + 1000;
    currentRow = other.currentRow;
    currentCol = other.currentCol;
    isActive = other.isActive;
    isGreedy = other.isGreedy;

    // Setup for distrubution of items
    int tmpItemsInBag = other.itemsInBag;
    T loot[20];

    // Copy the other robber loot to the loot array
    for (int i = 0; i < tmpItemsInBag; i++) {
        loot[i] = other.bag[i];
    }

    other.resetBag();

    // Distribute items between bags randomly
    for (int i = 0; i < tmpItemsInBag; i++) {
        int randRobber = rand() % 2;
        if (randRobber == 0) {
            bag[itemsInBag] = loot[i];
            incrementItemsInBag();
        } else {
            bag[other.itemsInBag] = other.bag[i];
            other.incrementItemsInBag();
        }
    }
}

// Increment/decrement items in bag
template <class T>
void Robber<T>::incrementItemsInBag() {
    itemsInBag++;
}

template <class T>
void Robber<T>::decrementItemsInBag() {
    itemsInBag--;
}

template <class T>
void Robber<T>::resetBag() {
    for (int i = 0; i < itemsInBag; i++) {
        bag[i] = T();
    }
    itemsInBag = 0;
}

template <class T>
void Robber<T>::pickUpLoot(T loot) {
    if (itemsInBag < 20) {
        // Pick up the item
        bag[itemsInBag] = loot;
        itemsInBag++;
        valueOfJewels += loot.getValue();
    } else {
        // Robber is full. Do nothing
        ;
    }
}

template <class T>
Robber<T>& Robber<T>::operator--() {
    if (itemsInBag > 0) {
        valueOfJewels -= bag[itemsInBag - 1].getValue();
        bag[itemsInBag - 1] = T();
        itemsInBag--;
    }

    return *this;
}

template <class T>
void Robber<T>::move() {
    bool directionIsValid = false;

    // Get a valid direction
    while (!directionIsValid) {
        int direction = rand() % 8;
        switch(direction) {
            case 0:
                if (currentRow > 0 && currentCol > 0) { // Move is valid
                    directionIsValid = true;
                    currentRow--;
                    currentCol--;
                }
                break;
            case 1:
                if (currentRow > 0) { // Move is valid
                    directionIsValid = true;
                    currentRow--;
                }
                break;

            case 2: 
                if (currentRow > 0 && currentCol  < 12) { // Move is valid
                    directionIsValid = true;
                    currentRow--;
                    currentCol++;
                }
                break;

            case 3:
                if(currentCol > 0) { // Move is valid
                    directionIsValid = true;
                    currentCol--;
                }
                break;

            case 4:
                if(currentCol < 12) { // Move is valid
                    directionIsValid = true;
                    currentCol++;
                }
                break;

            case 5:
                if(currentRow < 10 && currentCol > 0) { // Move is valid
                    directionIsValid = true;
                    currentRow++;
                    currentCol--;
                }
                break;

            case 6:
                if (currentRow < 10) { // Move is valid
                    directionIsValid = true;
                    currentRow++;
                }
                break;

            case 7:
                if (currentRow < 10 && currentCol < 12) { // Move is valid
                    directionIsValid = true;
                    currentRow++;
                    currentCol++;
                }
                break;
                
            default:
                // This should never happen 
                cout << "Error with random direction.";
                break;
        }
    }

    return;
}

template <class T>
int Robber<T>::getValueOfLootInBag() {
    int total = 0;
    for (int i = 0; i < itemsInBag; i++) {
        total += bag[i].getValue();
    }

    return total;
}