// Programmers: Gavin Sutherland and Jason Ni
// Date: 05/01/2024
// File: jewelImp.cpp
// Purpose: Contains the Jewel class implementaion

#include "jewel.h"

// Constructor overload

Jewel Jewel::operator*(const int multiplier) {
    value *= multiplier;
    return *this;
}

Jewel Jewel::operator*=(int multiplier) {
    value *= multiplier;
    return *this;
}