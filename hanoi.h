#pragma once

#include "stack.h"
#include <stdbool.h>

// This determines the difficulty of the game at compile time.
#define NUMBER_DISKS 3

typedef struct hanoiGame {
    PtStack towers[3]; //always three towers
} HanoiGame;

typedef struct hanoiGame* PtHanoiGame;

/**
 * @brief Creates a new game data structure.
 * 
 * This function must initialize the three towers and
 * place all disks in the first tower.
 * 
 * @return an initilized game data structure. 
 */
HanoiGame hanoiInit();

/**
 * @brief Performs necessary memory deallocation.
 * 
 * @param game game to deallocate.
 */
void hanoiCleanup(PtHanoiGame game);

/**
 * @brief Prints the state of a game.
 * 
 * @param game game to print.
 */
void hanoiPrint(PtHanoiGame game);

/**
 * @brief Performs a move on a ongoing game.
 * 
 * See Towers of Hanoi rules.
 * 
 * @param game game in which to perform the move
 * @param towerFrom tower number (1, 2 or 3) from which to remove a disk
 * @param towerTo tower number (1, 2 or 3) onto which a disk is to be placed
 * @return true if the move is valid and was performed
 * @return false if the move is invalid or a tower number is invalid
 */
bool hanoiMakeMove(PtHanoiGame game, int towerFrom, int towerTo);

/**
 * @brief Checks whether a game is solved successfully.
 * 
 * A game is solved when all disks are at tower number 3.
 * 
 * @param game the game to check.
 * @return true if game is solved.
 * @return false if game is not yet solved.
 */
bool hanoiSolved(PtHanoiGame game);