/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief Towers of Hanoi game in C.
 * @version 0.1
 * @date 2022-05-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "hanoi.h"
#include "input.h"

int main() {
    
    printf("### Welcome to Towers of Hanoi. Enjoy the game 🙂 ###\n\n");
    HanoiGame game = hanoiInit();

    while(!hanoiSolved(&game)) {
        hanoiPrint(&game);

        int from, to;
        printf("Whats your next move? 0 to quit.\n");
        
        printf("From [1-3]: ");
        readInteger(&from);
        if(from == 0) break;

        printf("To [1-3]: ");
        readInteger(&to);
        if(to == 0) break;

        bool valid = hanoiMakeMove(&game, from, to);
        if(!valid) {
            printf("\n🛑 The requested move is invalid! Please try again.\n");
        }
    }

    if(hanoiSolved(&game)) {
        hanoiPrint(&game);
        printf("You won! 🥳 Congratulations! \n");
    }

    printf("\n\nThanks for playing. Bye!\n");
    hanoiCleanup(&game);

    return EXIT_SUCCESS;
}