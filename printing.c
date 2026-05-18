#include <stdio.h>

#include "printing.h"

void printFieldUser(char gameField[GAME_FIELD_LEN][GAME_FIELD_HEIGHT], int cursorPositionX, int cursorPositionY){
    printf("+---------------------------------------------------------------+\n");

    for(int i = 0; i < GAME_FIELD_HEIGHT; i++){
        for(int j = 0; j < GAME_FIELD_LEN; j++){
            if(cursorPositionX == j && cursorPositionY == i){
                printf("| \033[1;35m%c\033[0m ", gameField[j][i]);
            } else{
                printf("| %c ", gameField[j][i]);
            }
            if(j == GAME_FIELD_LEN - 1){
                printf("|\n");
            }
        }

        if(i < GAME_FIELD_HEIGHT - 1){
            printf("+");
                for(int j = 0; j < GAME_FIELD_LEN; j++){
                    printf("---+");
                }
            printf("\n");
        }
    }

    printf("+---------------------------------------------------------------+\n");
}

void printMinesweeper(){
    printf(" __       __  __\n");
    printf("|  \\     /  \\|  \\\n");
    printf("| $$\\   /  $$ \\$$ _______    ______    _______  __   __   __   ______    ______    ______    ______    ______\n");
    printf("| $$$\\ /  $$$|  \\|       \\  /      \\  /       \\|  \\ |  \\ |  \\ /      \\  /      \\  /      \\  /      \\  /      \\\n");
    printf("| $$$$\\  $$$$| $$| $$$$$$$\\|  $$$$$$\\|  $$$$$$$| $$ | $$ | $$|  $$$$$$\\|  $$$$$$\\|  $$$$$$\\|  $$$$$$\\|  $$$$$$\\\n");
    printf("| $$\\$$ $$ $$| $$| $$  | $$| $$    $$ \\$$    \\ | $$ | $$ | $$| $$    $$| $$    $$| $$  | $$| $$    $$| $$   \\$$\n");
    printf("| $$ \\$$$| $$| $$| $$  | $$| $$$$$$$$ _\\$$$$$$\\| $$_/ $$_/ $$| $$$$$$$$| $$$$$$$$| $$__/ $$| $$$$$$$$| $$\n");
    printf("| $$  \\$ | $$| $$| $$  | $$ \\$$     \\|       $$ \\$$   $$   $$ \\$$     \\ \\$$     \\| $$    $$ \\$$     \\| $$\n");
    printf(" \\$$      \\$$ \\$$ \\$$   \\$$  \\$$$$$$$ \\$$$$$$$   \\$$$$$\\$$$$   \\$$$$$$$  \\$$$$$$$| $$$$$$$   \\$$$$$$$ \\$$ \n");
    printf("                                                                                 | $$\n");
    printf("                                                                                 | $$\n");
    printf("                                                                                  \\$$\n");
    printf("\n");
}