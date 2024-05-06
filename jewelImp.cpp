// Programmers: Gavin Sutherland (gas2bt, 101) and Jason Ni (Jnwkb, 301)
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