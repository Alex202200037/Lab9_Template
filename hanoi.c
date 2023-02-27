#include "hanoi.h"
#include "disk.h"
#include <stdio.h>
#include <stdlib.h>

HanoiGame hanoiInit() {
    HanoiGame game;

    // Create a new stack to represent each tower.
    // There are always three towers.
    for(int i=0; i<3; i++) {
        game.towers[i] = NULL; //TODO: create a new stack
    }

    //Place all disks in first tower, i.e., in game.towers[0]
    //the larger disk must sit at the bottom of the tower

    //TODO: constant NUMBER_DISKS defines the disk count 

    return game;
}

void hanoiCleanup(PtHanoiGame game) {
    //TODO...
}

void hanoiPrint(PtHanoiGame game) {
    printf("### GAME STATE ###\n");

    // Print all tower's contents
    for(int i=0; i<3; i++) {
        printf("\n🗼 Tower %d: \n", (i+1));
        stackPrint(game->towers[i]);
    }

    printf("\n##################\n");
}

bool hanoiMakeMove(PtHanoiGame game, int towerFrom, int towerTo) {
    //TODO...
    return false;
}

bool hanoiSolved(PtHanoiGame game) {
    //TODO...
    return false;
}