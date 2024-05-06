// Programmers: Gavin Sutherland (gas2bt, 101) and Jason Ni (Jnwkb, 301)
// Date: 05/02/2024
// File: jewel.h
// Purpose: Main logic 

#include <iostream>
#include <cstdlib>
#include <cmath>

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
        Jewel newJewel = Jewel(uniquePoint.row, uniquePoint.col);
        city.setValueAtCoordinate('J', uniquePoint.row, uniquePoint.col);
        jewels[i] = newJewel;
    }

    // List of Robbers
    Robber<Jewel> robbers[20];

    // Normal Robbers
    for (int i = 0; i < 2; i++) {
        Point uniquePoint = city.getUniquePosition();
        Robber<Jewel> newRobber = Robber<Jewel>(getUniqueID(), uniquePoint.row, uniquePoint.col, true, false);
        city.setValueAtCoordinate('r', uniquePoint.row, uniquePoint.col);
        robbers[i] = newRobber;
    }

    //Greedy Robbers
    for (int i = 0; i < 2; i++) {
        Point uniquePoint = city.getUniquePosition();
        Robber<Jewel> newRobber = Robber<Jewel>(getUniqueID(), uniquePoint.row, uniquePoint.col, true, true);
        city.setValueAtCoordinate('r', uniquePoint.row, uniquePoint.col);
        robbers[i + 2] = newRobber;
    }

    int numRobbers = 4;

    // List of Police
    Police police[3];

    // Get their coordinates
    for (int i = 0; i < 3; i++) {
        Point uniquePoint = city.getUniquePosition();
        Police newPolice = Police(getUniqueID(), uniquePoint.row, uniquePoint.col);
        city.setValueAtCoordinate('P', uniquePoint.row, uniquePoint.col);
        police[i] = newPolice;
    }

    // Update/Print City Board
    city.template updateBoard(jewels, police, robbers, numRobbers);
    city.printGrid();

    // START MAIN PROGRAM LOGIC
    int turns = 30;

    for (int i = 0; i < turns; i++) {
        cout << "==============================" << endl;
        cout << "Turn #" << i+1 << endl;
        // Ordinary Robbers Move
        // Loop through all of the robbers
        for (int j = 0; j < numRobbers; j++) {
            if (robbers[j].robberIsActive() && !robbers[j].robberIsGreedy()) {
                // Check for immobilization
                if (robbers[j].getTurnsLeftImmobilized() > 0) {
                    // Robber is immobilized. Decrement counter
                    cout << "Robber is currently imobilized." << endl;
                    robbers[j].decrementImmobilizeCounter();
                    continue;
                }

                // If the robber is able to move, do so.
                cout << "Robber #" << robbers[j].getID() << " moved from ("<<robbers[j].getRow()<<", "<<robbers[j].getCol();
                // move the robber
                robbers[j].move();
                cout << ") to (" << robbers[j].getRow() << ", " << robbers[j].getCol() << ")" << endl;

                // Check what happens based on where they land
                // JEWEL
                if (city.getValueAtCoordinate(robbers[j].getRow(), robbers[j].getCol()) == 'J') {
                    cout << "Robber #" << robbers[j].getID() << " found a jewel worth $";
                    // Pick up the loot and put it in the bag
                    robbers[j].pickUpLoot(jewels[getIndexOfJewelAtPosition(jewels, robbers[j].getRow(), robbers[j].getCol())]);
                    jewels[getIndexOfJewelAtPosition(jewels, robbers[j].getRow(), robbers[j].getCol())].setPickedUp(true);
                    cout << jewels[getIndexOfJewelAtPosition(jewels, robbers[j].getRow(), robbers[j].getCol())].getValue() << endl;;
                    robbers[j].resetImmobilizeCounter();

                    // Check for extra robber spawning
                    if (robbers[j].getValueOfLootInBag() >= 1600 && !robbers[j].getHasSpawnedOtherRobber()) {
                        cout << "Threshold reached. Spawing new robber" << endl;
                        Robber<Jewel> newRobber = Robber<Jewel>(robbers[j]);
                        numRobbers++;
                        robbers[numRobbers] = newRobber;
                        robbers[j].disableRobberSpawning();
                    }
                }

                // POLICE
                if (city.getValueAtCoordinate(robbers[j].getRow(), robbers[j].getCol()) == 'P') {
                    cout << "Robber #" << robbers[j].getID() << " ran into a cop. Got arrested" << endl;
                    // Robber is arrested
                    police[getIndexOfOfficerAtPosition(police, robbers[j].getRow(), robbers[j].getCol())].arrest(robbers[j], false);
                }

                // NOT A JEWEL
                if (city.getValueAtCoordinate(robbers[j].getRow(), robbers[j].getCol()) != 'J') {
                    // Add 1 to the number of turns without a jewel
                    robbers[j].incrementTurnsWithoutJewel();
                    if (robbers[j].getTurnsWithoutJewel() == 5) {
                        // Immobilize robber
                        cout << "Robber #" << robbers[j].getID() << " hasn't picked up a jewel in 5 turns. Immobilized!" << endl;
                        robbers[j].immobilize();
                        robbers[j].resetImmobilizeCounter();
                    }
                }

                // Robber tripping
                if (rand() % 10 < 6) {
                    cout << "Robber #" << robbers[j].getID() << " tripped" << endl;
                    if (robbers[j].getNumItemsInBag() > 0) {
                        // Find an open cell near the point
                        Point openPoint = city.getOpenSpotNearPosition(robbers[j].getRow(), robbers[j].getCol());

                        // Place the last piece of loot in the robbers bad in the new spot
                        if (openPoint.row != -1) {
                            // There is an open point. Find where the loot was originally and update the jewel in the jewel array
                            int rowOfLoot = robbers[j].getRowOfLastItem();
                            cout << rowOfLoot << endl;
                            int colOfLoot = robbers[j].getColOfLastItem();
                            cout << colOfLoot << endl;
                            int indexOfLoot = getIndexOfJewelAtPosition(jewels, rowOfLoot, colOfLoot);
                            if (indexOfLoot != -1){
                                jewels[indexOfLoot].setNewLocation(openPoint.row, openPoint.col);
                                jewels[indexOfLoot].setPickedUp(false);
                                --robbers[j];
                            }
                        } else {
                            --robbers[j];
                        }
                    }
                }
            }
        }
            
        // Greedy Robbers Move
        // Loop through all of the robbers
        for (int j = 0; j < numRobbers; j++) {
            if (robbers[j].robberIsActive() && robbers[j].robberIsGreedy()) {
                // Check for immobilization
                if (robbers[j].getTurnsLeftImmobilized() > 0) {
                    // Robber is immobilized. Decrement counter
                    cout << "Robber is currently imobilized." << endl;
                    robbers[j].decrementImmobilizeCounter();
                    continue;
                }

                // If the robber is able to move, do so.
                cout << "Robber #" << robbers[j].getID() << " moved from ("<<robbers[j].getRow()<<", "<<robbers[j].getCol();
                // move the robber
                robbers[j].move();
                cout << ") to (" << robbers[j].getRow() << ", " << robbers[j].getCol() << ")" << endl;
                
                // Check what happens based on where they land
                // JEWEL
                if (city.getValueAtCoordinate(robbers[j].getRow(), robbers[j].getCol()) == 'J') {
                    cout << "Robber #" << robbers[j].getID() << " found a jewel worth $";
                    // Pick up the loot and put it in the bag
                    robbers[j].pickUpLoot(jewels[getIndexOfJewelAtPosition(jewels, robbers[j].getRow(), robbers[j].getCol())]);
                    jewels[getIndexOfJewelAtPosition(jewels, robbers[j].getRow(), robbers[j].getCol())].setPickedUp(true);
                    cout << jewels[getIndexOfJewelAtPosition(jewels, robbers[j].getRow(), robbers[j].getCol())].getValue() << endl;

                    // Check for extra robber spawning
                    if (robbers[j].getValueOfLootInBag() >= 1600 && !robbers[j].getHasSpawnedOtherRobber()) {
                        cout << "Threshold reached. Spawing new robber" << endl;
                        Robber<Jewel> newRobber = Robber<Jewel>(robbers[j]);
                        numRobbers++;
                        robbers[numRobbers] = newRobber;
                        robbers[j].disableRobberSpawning();
                    }

                    // Check for moving again
                    if (jewels[getIndexOfJewelAtPosition(jewels, robbers[j].getRow(), robbers[j].getCol())].getValue() % 2 == 0) {
                        // MOVE AGAIN
                        city.updateBoard(jewels, police, robbers, numRobbers);
                        // If the robber is able to move, do so.
                        cout << "Robber #" << robbers[j].getID() << " moved again from ("<<robbers[j].getRow()<<", "<<robbers[j].getCol();
                        // move the robber
                        robbers[j].move();
                        cout << ") to (" << robbers[j].getRow() << ", " << robbers[j].getCol() << ")" << endl;
                        
                        // Check what happens based on where they land
                        // JEWEL
                        if (city.getValueAtCoordinate(robbers[j].getRow(), robbers[j].getCol()) == 'J') {
                            cout << "Robber #" << robbers[j].getID() << " found a jewel worth $";
                            // Pick up the loot and put it in the bag
                            robbers[j].pickUpLoot(jewels[getIndexOfJewelAtPosition(jewels, robbers[j].getRow(), robbers[j].getCol())]);
                            jewels[getIndexOfJewelAtPosition(jewels, robbers[j].getRow(), robbers[j].getCol())].setPickedUp(true);
                            cout << jewels[getIndexOfJewelAtPosition(jewels, robbers[j].getRow(), robbers[j].getCol())].getValue() << endl;

                            // Check for extra robber spawning
                            if (robbers[j].getValueOfLootInBag() >= 1600 && !robbers[j].getHasSpawnedOtherRobber()) {
                                cout << "Threshold reached. Spawing new robber" << endl;
                                Robber<Jewel> newRobber = Robber<Jewel>(robbers[j]);
                                numRobbers++;
                                robbers[numRobbers] = newRobber;
                                robbers[j].disableRobberSpawning();
                            }

                            // Check for moving again
                            if (jewels[getIndexOfJewelAtPosition(jewels, robbers[j].getRow(), robbers[j].getCol())].getValue() % 2 == 0) {
                                // THIRD MOVE
                                city.updateBoard(jewels, police, robbers, numRobbers);
                                // If the robber is able to move, do so.
                                cout << "Robber #" << robbers[j].getID() << " moved again from ("<<robbers[j].getRow()<<", "<<robbers[j].getCol();
                                // move the robber
                                robbers[j].move();
                                cout << ") to (" << robbers[j].getRow() << ", " << robbers[j].getCol() << ")" << endl;
                                
                                // Check what happens based on where they land
                                // JEWEL
                                if (city.getValueAtCoordinate(robbers[j].getRow(), robbers[j].getCol()) == 'J') {
                                    cout << "Robber #" << robbers[j].getID() << " found a jewel worth $";
                                    // Pick up the loot and put it in the bag
                                    robbers[j].pickUpLoot(jewels[getIndexOfJewelAtPosition(jewels, robbers[j].getRow(), robbers[j].getCol())]);
                                    jewels[getIndexOfJewelAtPosition(jewels, robbers[j].getRow(), robbers[j].getCol())].setPickedUp(true);
                                    cout << jewels[getIndexOfJewelAtPosition(jewels, robbers[j].getRow(), robbers[j].getCol())].getValue() << endl;

                                    // Check for extra robber spawning
                                    if (robbers[j].getValueOfLootInBag() >= 1600 && !robbers[j].getHasSpawnedOtherRobber()) {
                                        cout << "Threshold reached. Spawing new robber" << endl;
                                        Robber<Jewel> newRobber = Robber<Jewel>(robbers[j]);
                                        numRobbers++;
                                        robbers[numRobbers] = newRobber;
                                        robbers[j].disableRobberSpawning();
                                    }
                                }

                                // POLICE
                                if (city.getValueAtCoordinate(robbers[j].getRow(), robbers[j].getCol()) == 'P') {
                                    cout << "Robber #" << robbers[j].getID() << " ran into a cop. Got arrested" << endl;
                                    // Robber is arrested
                                    police[getIndexOfOfficerAtPosition(police, robbers[j].getRow(), robbers[j].getCol())].arrest(robbers[j], false);
                                }

                                // OTHER ROBBER
                                if (city.getValueAtCoordinate(robbers[j].getRow(), robbers[j].getCol()) == 'r' || city.getValueAtCoordinate(robbers[j].getRow(), robbers[j].getCol()) == 'R') {
                                    cout << "Robber #" << robbers[j].getID() << " found another robber. Losing half of current loot" << endl;
                                    // Robber looses half of their loot
                                    int lootToLose = floor(robbers[j].getNumItemsInBag());
                                    for (int k = 0; k < lootToLose; k++) {
                                        int rowOfLoot = robbers[j].getRowOfLastItem();
                                        int colOfLoot = robbers[j].getColOfLastItem();
                                        int indexOfLoot = getIndexOfJewelAtPosition(jewels, rowOfLoot, colOfLoot);

                                        if (city.getValueAtCoordinate(rowOfLoot, colOfLoot) == ' ') {
                                            // Place the last piece of loot in the robbers bad in the new spot
                                            jewels[indexOfLoot].setPickedUp(false);
                                            --robbers[j];
                                        } else {
                                            // The position was taken
                                            Point newPoint = city.getUniquePosition();
                                            jewels[indexOfLoot].setNewLocation(newPoint.row, newPoint.col);
                                            jewels[indexOfLoot].setPickedUp(false);
                                        }
                                        --robbers[j];
                                    }
                                }

                                // NOT A JEWEL
                                if (city.getValueAtCoordinate(robbers[j].getRow(), robbers[j].getCol()) != 'J') {
                                    // Add 1 to the number of turns without a jewel
                                    robbers[j].incrementTurnsWithoutJewel();
                                    if (robbers[j].getTurnsWithoutJewel() == 5) {
                                        // Immobilize robber
                                        cout << "Robber #" << robbers[j].getID() << " hasn't picked up a jewel in 5 turns. Immobilized!" << endl;
                                        robbers[j].immobilize();
                                        robbers[j].resetImmobilizeCounter();
                                    }
                                }

                                // Robber tripping
                                if (rand() % 10 < 6) {
                                    cout << "Robber #" << robbers[j].getID() << " tripped" << endl;
                                    if (robbers[j].getNumItemsInBag() > 0) {
                                        // Find an open cell near the point
                                        Point openPoint = city.getOpenSpotNearPosition(robbers[j].getRow(), robbers[j].getCol());

                                        // Place the last piece of loot in the robbers bad in the new spot
                                        if (openPoint.row != -1) {
                                            // There is an open point. Find where the loot was originally and update the jewel in the jewel array
                                            int rowOfLoot = robbers[j].getRowOfLastItem();
                                            cout << rowOfLoot << endl;
                                            int colOfLoot = robbers[j].getColOfLastItem();
                                            cout << colOfLoot << endl;
                                            int indexOfLoot = getIndexOfJewelAtPosition(jewels, rowOfLoot, colOfLoot);
                                            if (indexOfLoot != -1){
                                                jewels[indexOfLoot].setNewLocation(openPoint.row, openPoint.col);
                                                jewels[indexOfLoot].setPickedUp(false);
                                                --robbers[j];
                                            }
                                        } else {
                                            --robbers[j];
                                        }
                                    }
                                }
                            } // END THIRD MOVE
                        } // END PICKING UP JEWEL FOR 2ND MOVE

                        // POLICE
                        if (city.getValueAtCoordinate(robbers[j].getRow(), robbers[j].getCol()) == 'P') {
                            cout << "Robber #" << robbers[j].getID() << " ran into a cop. Got arrested" << endl;
                            // Robber is arrested
                            police[getIndexOfOfficerAtPosition(police, robbers[j].getRow(), robbers[j].getCol())].arrest(robbers[j], false);
                        }

                        // OTHER ROBBER
                        if (city.getValueAtCoordinate(robbers[j].getRow(), robbers[j].getCol()) == 'r' || city.getValueAtCoordinate(robbers[j].getRow(), robbers[j].getCol()) == 'R') {
                            cout << "Robber #" << robbers[j].getID() << " found another robber. Losing half of current loot" << endl;
                            // Robber looses half of their loot
                            int lootToLose = floor(robbers[j].getNumItemsInBag());
                            for (int k = 0; k < lootToLose; k++) {
                                int rowOfLoot = robbers[j].getRowOfLastItem();
                                int colOfLoot = robbers[j].getColOfLastItem();
                                int indexOfLoot = getIndexOfJewelAtPosition(jewels, rowOfLoot, colOfLoot);

                                if (city.getValueAtCoordinate(rowOfLoot, colOfLoot) == ' ') {
                                    // Place the last piece of loot in the robbers bad in the new spot
                                    jewels[indexOfLoot].setPickedUp(false);
                                    --robbers[j];
                                } else {
                                    // The position was taken
                                    Point newPoint = city.getUniquePosition();
                                    jewels[indexOfLoot].setNewLocation(newPoint.row, newPoint.col);
                                    jewels[indexOfLoot].setPickedUp(false);
                                }
                                --robbers[j];
                            }
                        }

                        // NOT A JEWEL
                        if (city.getValueAtCoordinate(robbers[j].getRow(), robbers[j].getCol()) != 'J') {
                            // Add 1 to the number of turns without a jewel
                            robbers[j].incrementTurnsWithoutJewel();
                            if (robbers[j].getTurnsWithoutJewel() == 5) {
                                // Immobilize robber
                                cout << "Robber #" << robbers[j].getID() << " hasn't picked up a jewel in 5 turns. Immobilized!" << endl;
                                robbers[j].immobilize();
                                robbers[j].resetImmobilizeCounter();
                            }
                        }

                        // Robber tripping
                        if (rand() % 10 < 6) {
                            cout << "Robber #" << robbers[j].getID() << " tripped" << endl;
                            if (robbers[j].getNumItemsInBag() > 0) {
                                // Find an open cell near the point
                                Point openPoint = city.getOpenSpotNearPosition(robbers[j].getRow(), robbers[j].getCol());

                                // Place the last piece of loot in the robbers bad in the new spot
                                if (openPoint.row != -1) {
                                    // There is an open point. Find where the loot was originally and update the jewel in the jewel array
                                    int rowOfLoot = robbers[j].getRowOfLastItem();
                                    cout << rowOfLoot << endl;
                                    int colOfLoot = robbers[j].getColOfLastItem();
                                    cout << colOfLoot << endl;
                                    int indexOfLoot = getIndexOfJewelAtPosition(jewels, rowOfLoot, colOfLoot);
                                    if (indexOfLoot != -1){
                                        jewels[indexOfLoot].setNewLocation(openPoint.row, openPoint.col);
                                        jewels[indexOfLoot].setPickedUp(false);
                                        --robbers[j];
                                    }
                                } else {
                                    --robbers[j];
                                }
                            }
                        }
                    } // END FIRST MOVE AGAIN
                } // END PICKING UP JEWEL

                // POLICE
                if (city.getValueAtCoordinate(robbers[j].getRow(), robbers[j].getCol()) == 'P') {
                    cout << "Robber #" << robbers[j].getID() << " ran into a cop. Got arrested" << endl;
                    // Robber is arrested
                    police[getIndexOfOfficerAtPosition(police, robbers[j].getRow(), robbers[j].getCol())].arrest(robbers[j], false);
                }

                // OTHER ROBBER
                if (city.getValueAtCoordinate(robbers[j].getRow(), robbers[j].getCol()) == 'r' || city.getValueAtCoordinate(robbers[j].getRow(), robbers[j].getCol()) == 'R') {
                    cout << "Robber #" << robbers[j].getID() << " found another robber. Losing half of current loot" << endl;
                    // Robber looses half of their loot
                    int lootToLose = floor(robbers[j].getNumItemsInBag());
                    for (int k = 0; k < lootToLose; k++) {
                        int rowOfLoot = robbers[j].getRowOfLastItem();
                        int colOfLoot = robbers[j].getColOfLastItem();
                        int indexOfLoot = getIndexOfJewelAtPosition(jewels, rowOfLoot, colOfLoot);

                        if (city.getValueAtCoordinate(rowOfLoot, colOfLoot) == ' ') {
                            // Place the last piece of loot in the robbers bad in the new spot
                            jewels[indexOfLoot].setPickedUp(false);
                            --robbers[j];
                        } else {
                            // The position was taken
                            Point newPoint = city.getUniquePosition();
                            jewels[indexOfLoot].setNewLocation(newPoint.row, newPoint.col);
                            jewels[indexOfLoot].setPickedUp(false);
                        }
                        --robbers[j];
                    }
                }

                // NOT A JEWEL
                if (city.getValueAtCoordinate(robbers[j].getRow(), robbers[j].getCol()) != 'J') {
                    // Add 1 to the number of turns without a jewel
                    robbers[j].incrementTurnsWithoutJewel();
                    if (robbers[j].getTurnsWithoutJewel() == 5) {
                        // Immobilize robber
                        cout << "Robber #" << robbers[j].getID() << " hasn't picked up a jewel in 5 turns. Immobilized!" << endl;
                        robbers[j].immobilize();
                        robbers[j].resetImmobilizeCounter();
                    }
                }

                // Robber tripping
                if (rand() % 10 < 6) {
                    cout << "Robber #" << robbers[j].getID() << " tripped" << endl;
                    if (robbers[j].getNumItemsInBag() > 0) {
                        // Find an open cell near the point
                        Point openPoint = city.getOpenSpotNearPosition(robbers[j].getRow(), robbers[j].getCol());

                        // Place the last piece of loot in the robbers bad in the new spot
                        if (openPoint.row != -1) {
                            // There is an open point. Find where the loot was originally and update the jewel in the jewel array
                            int rowOfLoot = robbers[j].getRowOfLastItem();
                            cout << rowOfLoot << endl;
                            int colOfLoot = robbers[j].getColOfLastItem();
                            cout << colOfLoot << endl;
                            int indexOfLoot = getIndexOfJewelAtPosition(jewels, rowOfLoot, colOfLoot);
                            if (indexOfLoot != -1){
                                jewels[indexOfLoot].setNewLocation(openPoint.row, openPoint.col);
                                jewels[indexOfLoot].setPickedUp(false);
                                --robbers[j];
                            }
                        } else {
                            --robbers[j];
                        }
                    }
                }

                // Update the bpoard with new information
                city.template updateBoard(jewels, police, robbers, numRobbers);
            }
        }

        // Police Move
        for (int j = 0; j < 3; j++) {
            cout << "Police #" << police[j].getID() << " moved from ("<<police[j].getRow()<<", "<<police[j].getCol();
            // move the robber
            police[j].move();
            cout << ") to (" << police[j].getRow() << ", " << police[j].getCol() << ")" << endl;
            
            // SINGLE ROBBER
            if (city.getValueAtCoordinate(police[j].getRow(), police[j].getCol()) == 'r') {
                cout << "Police #" << police[j].getID() << " found a robber" << endl;
                cout << "Arresting robber at index " << getIndexOfRobberAtPosition(robbers, numRobbers, police[j].getRow(), police[j].getCol()) << endl;
                police[j].template arrest(robbers[getIndexOfRobberAtPosition(robbers, numRobbers, police[j].getRow(), police[i].getCol())], false);
            }

            // MULTIPLE ROBBERS
            if (city.getValueAtCoordinate(police[j].getRow(), police[j].getCol()) == 'R') {
                cout << "Police #" << police[j].getID() << " found multiple robbers" << endl;
                police[j].template arrest(robbers[getIndexOfRobberAtPosition(robbers, numRobbers, police[j].getRow(), police[i].getCol())], true);
            }

            // JEWEL
            if (city.getValueAtCoordinate(police[j].getRow(), police[j].getCol()) == 'J') {
                cout << "Police #" << police[j].getID() << " found a jewel" << endl;
                jewels[getIndexOfJewelAtPosition(jewels, police[j].getRow(), police[j].getCol())].setPickedUp(true);
            }

            // OFFICER
            if (city.getValueAtCoordinate(police[j].getRow(), police[j].getCol()) == 'P') {
                cout << "Police #" << police[j].getID() << " found another officer. " << endl;
                int indexOfOtherOfficer = getIndexOfOfficerAtPositionAsOfficer(police, police[j].getRow(), police[j].getCol(), j);
                int totalLootValue = police[j].getTotalConfiscatedLoot() + police[indexOfOtherOfficer].getTotalConfiscatedLoot();

                cout << "Prev totals: (" << police[j].getTotalConfiscatedLoot() << ", " << police[indexOfOtherOfficer].getTotalConfiscatedLoot() << ")" << endl;
                
                // If the value is even, distribute evenly
                if (totalLootValue  % 2 == 0) {
                    police[j].setTotalConfiscatedLoot(totalLootValue / 2);
                    police[indexOfOtherOfficer].setTotalConfiscatedLoot(totalLootValue / 2);
                } else {
                    // Distrubute almost evenly
                    police[j].setTotalConfiscatedLoot(ceil(totalLootValue / 2));
                    police[indexOfOtherOfficer].setTotalConfiscatedLoot(floor(totalLootValue / 2));
                }

                cout << "New totals: (" << police[j].getTotalConfiscatedLoot() << ", " << police[indexOfOtherOfficer].getTotalConfiscatedLoot() << ")" << endl;
            }

            // Update the bpoard with new information
            city.template updateBoard(jewels, police, robbers, numRobbers);
        }

        city.printGrid();

        // Check for exit conditions
        // If $6000 of jewels have been collected, end the game
        if (robbers[0].valueOfJewels >= 6000) {
            cout << "The robbers have recovered $6000 worth of loot. The game is over." << endl;
            break;
        }

        // No more active robbers
        bool isAnActiveRobber = false;
        for (int j = 0; j < numRobbers; j++) {
            if (robbers[j].robberIsActive()) {
                isAnActiveRobber = true;
                break;
            }
        }

        if (!isAnActiveRobber) {
            cout << "All robbers have been arrested." << endl;
        }


        // Turns run out
        if (i == turns - 1) {
            cout << "The game ends after 80 turns! The robbers escape." << endl;
        }

    }

    // Chase summary
    // Police
    for (int i = 0; i < 3; i++) {
        cout << "Police id: " << police[i].getID() << endl;
        cout << "\tConfiscated jewels amount: $" << police[i].getTotalConfiscatedLoot() << endl;
        cout << "\tFinal number of robbers caught: " << police[i].getTotalRobbersCaught() << endl << endl;
    }

    // Robbers
    for (int i = 0; i < numRobbers; i++) {
        if (robbers[i].robberIsGreedy()) {
            cout << "Greedy robber id: " << robbers[i].getID() << endl;
        } else {
            cout << "Ordinary robber id: " << robbers[i].getID() << endl;
        }

        cout << "\tFinal number of jewels in bag: " << robbers[i].getNumItemsInBag() << endl;
        cout << "\tTotal jewel worth: " << robbers[i].getValueOfLootInBag() << endl;
    }

    return 0;
}