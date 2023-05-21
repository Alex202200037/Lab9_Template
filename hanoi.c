#include "hanoi.h"
#include "disk.h"
#include <stdio.h>
#include <stdlib.h>

HanoiGame hanoiInit() {
    HanoiGame game;

    // Create a new stack to represent each tower.
    // There are always three towers.
    for(int i=0; i<3; i++) {
        game.towers[i] = stackCreate(); 
    }


    for(int i=NUMBER_DISKS; i>0; i--){
        Disk d = diskCreate(i);
        stackPush(game.towers[0],d);
    }
    //Place all disks in first tower, i.e., in game.towers[0]
    //the larger disk must sit at the bottom of the tower

    

    return game;
}

void hanoiCleanup(PtHanoiGame game) {
    for(int i=0; i<3; i++){
        PtStack stack;
        stackDestroy(&game->towers[i]);
        stack=NULL;
    }
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
    Disk d, d1;

    if((towerFrom<1 || towerFrom > 3) || (towerTo <1 || towerTo >3)){
        return false;
    }

    towerFrom--;
    towerTo--;

    if(stackIsEmpty(game->towers[towerFrom])){
        return false;
    }
    if(stackIsEmpty(game->towers[towerTo])){
        stackPop(game->towers[towerFrom],&d);
        stackPush(game->towers[towerTo],d);
        return true;
    }

    stackPeek(game->towers[towerFrom],&d);
    stackPeek(game->towers[towerTo],&d1);

    if(d.size < d1.size){
        stackPop(game->towers[towerFrom],&d);
        stackPush(game->towers[towerTo],d);
        return true;
    }

    return false;

}


bool hanoiSolved(PtHanoiGame game) {
    if(game == NULL){
        return false;
    }
    int size;
    stackSize(game->towers[2], &size);

    return stackIsEmpty(game->towers[0]) && stackIsEmpty(game->towers[1]) && size == NUMBER_DISKS;
}