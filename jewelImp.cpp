// Programmers: Gavin Sutherland and Jason Ni
// Date: 05/01/2024
// File: jewelImp.cpp
// Purpose: Contains the Jewel class implementaion


#include "jewel.h"

Jewel Jewel::operator*() {
    return Jewel(value * 2, xPos, yPos);
}

// void Jewel::operator*=(int multiplier) {
//     value *= multiplier;
// }