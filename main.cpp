// Programmers: Gavin Sutherland and Jason Ni
// Date: 05/02/2024
// File: jewel.h
// Purpose: Main logic 

#include <iostream>
#include <cstdlib>

#include "city.h"
#include "jewel.h"
#include "robber.h"
#include "police.h"
#include "header.h"

using namespace std;

int main() {
    // Set seed to 100
    srand(100);

    // Initialize the city object
    City city;

    // Create the list of jewels
    Jewel jewels[60];
    
    // Get the random coordinates for the jewels. Each on should be unique.
    for (int i = 0; i < 60; i++) {
        // Get unique coordinate
        Point uniquePoint = city.getUniquePosition();
        Jewel newJewel = Jewel(0, uniquePoint.row, uniquePoint.col);
        jewels[i] = newJewel;
    }

    // List of Robbers
    Robber<Jewel> robbers[20];

    // Normal Robbers
    for (int i = 0; i < 2; i++) {
        Point uniquePoint = city.getUniquePosition();
        Robber<Jewel> newRobber = Robber<Jewel>(getUniqueID(), uniquePoint.row, uniquePoint.col, true, false);
        robbers[i] = newRobber;
    }

    //Greedy Robbers
    for (int i = 0; i < 2; i++) {
        Point uniquePoint = city.getUniquePosition();
        Robber<Jewel> newRobber = Robber<Jewel>(getUniqueID(), uniquePoint.row, uniquePoint.col, true, true);
        robbers[i + 2] = newRobber;
    }

    int numRobbers = 4;

    // List of Police
    Police police[3];

    // Get their coordinates
    for (int i = 0; i < 3; i++) {
        Point uniquePoint = city.getUniquePosition();
        Police newPolice = Police(getUniqueID(), uniquePoint.row, uniquePoint.col);
        police[i] = newPolice;
    }

    // Update/Print City Board
    city.template updateBoard(jewels, police, robbers, numRobbers);
    city.printGrid();

    // START MAIN PROGRAM LOGIC
    bool gameOver = false;
    while(!gameOver) {
        // Ordinary Robbers Move
        // Loop through all of the robbers
            // if the robber is normal and active
                // move the robber
                // Check what happens based on where they land
                // If you find a robber:
                    // Nothing happens
                // If you find a jewel:
                    // Pick up the loot and put it in the bag
                    // Check for extra robber spawning
                // If you find a police officer:
                    // Robber is arrested
                    
                // Update the bpoard with new information

        // Greedy Robbers Move
        // Loop through all of the robbers
            // if the robber is greedy and active
                // move the robber
                // Check what happens based on where they land
                // If you find a robber:
                    // Lose half of your loot
                // If you find a jewel:
                    // Pick up the loot and put it in the bag
                    // Check for extra robber spawning
                    // If the loot was an even number:
                        // Move again
                        // Check for previous conditions
                        // If you pick up an even jewel:
                            // Move one more time
                            // Check for all previous conditions
                // If you find a police officer:
                    // Robber is arrested
                    
                // Update the bpoard with new information

        // Police Move
        // Loop through all of the police
            // move the police
            // If they find a robber
                // Arrest them
            // If they find multiple robbers
                // Arrest all of them
            // If they find loot
                // Remove it from the grid
            // If they find an officer
                // Split money evenly between them




        if() {
            cout << "The robbbers wins the chase because the maximum turns of 80 have been reached!" << endl;
            gameOver = true;
        }
        else if() {
            cout << "The tobbers wins the chase because they reached $6000 of jewels!" << endl;
            gameOver = true;
        }
        else if() {
                
        }
    }
    

    return 0;
}