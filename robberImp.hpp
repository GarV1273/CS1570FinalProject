// Programmers: Gavin Sutherland and Jason Ni
// Date: 04/25/2024
// File: robberImp.hpp
// Purpose: Implementation for the Robber class (found in robber.h)

#include "robber.h"

// Copy constructor overload
template <class T>
Robber<T>::Robber(const Robber& other) {
    id = other.id;
    currentRow = other.currentRow;
    currentCol = other.currentCol;
    isActive = other.isActive;
    isGreedy = other.isGreedy;

    // Distribute items between bags
    // TODO Idk how to do this so we'll ask later
}

template <class T>
void Robber<T>::pickUpLoot(T loot) {
    if (itemsInBag < 20) {
        // Pick up the item
        bag[itemsInBag] = loot;
        itemsInBag++;
    } else {
        // Robber is full. Do nothing
        ;
    }
}

template <class T>
Robber<T>& Robber<T>::operator --() {

    bag[itemsInBag - 1] = Jewel();
    itemsInBag--;
}

template <class T>
void Robber<T>::move() {
    int direction = rand() % 8;

    bool directionIsValid = false;

    // Get a valid direction
    while (!directionIsValid) {
        switch(direction) {
            case 0:
                if (currentRow > 0 && currentCol > 0) { // Move is valid
                    directionIsValid = true;
                    currentRow--;
                    currentCol--;
                }
                break;
            case 1:
                if (currentCol > 0) { // Move is valid
                    directionIsValid = true;
                    currentRow--;
                }
                break;

            case 2: 
                if (currentRow < 10 && currentCol > 0) { // Move is valid
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
                cout < "Error with random direction.";
        }
    }
}



