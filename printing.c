#include "printing.h"

void printFieldUser(char gameField[GAME_FIELD_LEN][GAME_FIELD_HEIGHT], int cursorPositionX, int cursorPositionY){
    printf("+---------------------------------------------------------------+\n");

    for(int i = 0; i < GAME_FIELD_HEIGHT; i++){
        for(int j = 0; j < GAME_FIELD_LEN; j++){
            if(cursorPositionX == j && cursorPositionY == i){
                printf("| \033[6;35m%c\033[0m ", gameField[j][i]);
            } else{
                switch (gameField[j][i]){
                case '0':
                    printf("|\033[48;2;210;180;140m\x1b[90m   \033[0m"/*, gameField[j][i]*/);
                    break;

                case '1':
                    printf("|\033[48;2;210;180;140m\x1b[34m %c \033[0m", gameField[j][i]);
                    break;

                case '2':
                    printf("|\033[48;2;210;180;140m\x1b[32m %c \033[0m", gameField[j][i]);
                    break;

                case '3':
                    printf("|\033[48;2;210;180;140m\x1b[31m %c \033[0m", gameField[j][i]);
                    break;

                case '4':
                    printf("|\033[48;2;210;180;140m\x1b[35m %c \033[0m", gameField[j][i]);
                    break;

                case '5':
                    printf("|\033[48;2;210;180;140m\x1b[33m %c \033[0m", gameField[j][i]);
                    break;

                case '6':
                    printf("|\033[48;2;210;180;140m\x1b[36m %c \033[0m", gameField[j][i]);
                    break;

                case '7':
                    printf("|\033[48;2;210;180;140m\x1b[30m %c \033[0m", gameField[j][i]);
                    break;

                case '8':
                    printf("|\033[48;2;210;180;140m\x1b[90m %c \033[0m", gameField[j][i]);
                    break;
                
                default:
                    printf("\033[0m|");
                    //Choose one of the next three:
                    //printf("\033[42m   \033[0m");
                    printf("\033[42m ? \033[0m");
                    //printf("| %c ", gameField[j][i]);
                    break;
                }
            }
            if(j == GAME_FIELD_LEN - 1){
                printf("|\n");
            }
        }

        if(i < GAME_FIELD_HEIGHT - 1){
            printf("|");
            for(int j = 0; j < GAME_FIELD_LEN - 1; j++){
                printf("---+");
            }
            printf("---|\n");
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