#include "printing.h"

void printFieldUser(char gameField[GAME_FIELD_LEN][GAME_FIELD_HEIGHT], int cursorPositionX, int cursorPositionY, int cheat){
    printf("+---------------------------------------------------------------+\n");

    for(int i = 0; i < GAME_FIELD_HEIGHT; i++){
        for(int j = 0; j < GAME_FIELD_LEN; j++){
            if(cursorPositionX == j && cursorPositionY == i){
                printf("| \033[6;35m \033[0m ", gameField[j][i]);
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
                    printf("\033[42m");
                    if(gameField[j][i] <= 9){
                        if(cheat == 1 && gameField[j][i] == 9){
                            printf(" B");
                        } else {
                            printf("  ");
                        }
                    } else {
                        printf("\U0001F6A9");//needs UTF-8 and prints the flag
                    }
                    printf(" \033[0m");

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

void printYouWin(){
    printf(" __      __                                        __           \n");
    printf("|  \\    /  \\                                      |  \\         \n");
    printf(" \\$$\\  /  $$______   __    __        __   __   __  \\$$ _______  \n");
    printf("  \\$$\\/  $$/      \\ |  \\  |  \\      |  \\ |  \\ |  \\|  \\|       \\ \n");
    printf("   \\$$  $$|  $$$$$$\\| $$  | $$      | $$ | $$ | $$| $$| $$$$$$$\\ \n");
    printf("    \\$$$$ | $$  | $$| $$  | $$      | $$ | $$ | $$| $$| $$  | $$\n");
    printf("    | $$  | $$__/ $$| $$__/ $$      | $$_/ $$_/ $$| $$| $$  | $$\n");
    printf("    | $$   \\$$    $$ \\$$    $$       \\$$   $$   $$| $$| $$  | $$\n");
    printf("     \\$$    \\$$$$$$   \\$$$$$$         \\$$$$$\\$$$$  \\$$ \\$$   \\$$\n");
    printf("\n");
}

void printGameOver(){
    printf("  ______                                                                                  \n");
    printf(" /      \\                                                                                 \n");
    printf("|  $$$$$$\\  ______   ______ ____    ______          ______  __     __   ______    ______  \n");
    printf("| $$ __\\$$ |      \\ |      \\    \\  /      \\        /      \\|  \\   /  \\ /      \\  /      \\ \n");
    printf("| $$|    \\  \\$$$$$$\\| $$$$$$\\$$$$\\|  $$$$$$\\      |  $$$$$$\\$$\\ /  $$|  $$$$$$\\|  $$$$$$ \\ \n");
    printf("| $$ \\$$$$ /      $$| $$ | $$ | $$| $$    $$      | $$  | $$ \\$$\\  $$ | $$    $$| $$   \\$$ \n");
    printf("| $$__| $$|  $$$$$$$| $$ | $$ | $$| $$$$$$$$      | $$__/ $$  \\$$ $$  | $$$$$$$$| $$      \n");
    printf(" \\$$    $$ ß\\$$    $$| $$ | $$ | $$ \\$$     \\       \\$$    $$   \\$$$    \\$$     \\| $$      \n");
    printf("  \\$$$$$$   \\$$$$$$$ \\$$  \\$$  \\$$  \\$$$$$$$        \\$$$$$$     \\$      \\$$$$$$$ \\$$      \n");
    printf("\n");
}

void printMenu(){
    printf(" __       __\n");
    printf("|  \\     /  \\\n");
    printf("| $$\\   /  $$  ______   _______   __    __\n");
    printf("| $$$\\ /  $$$ /      \\ |       \\ |  \\  |  \\\n");
    printf("| $$$$\\  $$$$|  $$$$$$\\| $$$$$$$\\| $$  | $$\n");
    printf("| $$\\$$ $$ $$| $$    $$| $$  | $$| $$  | $$\n");
    printf("| $$ \\$$$| $$| $$$$$$$$| $$  | $$| $$__/ $$\n");
    printf("| $$  \\$ | $$ \\$$     \\| $$  | $$ \\$$    $$\n");
    printf(" \\$$      \\$$  \\$$$$$$$ \\$$   \\$$  \\$$$$$$ \n");
    printf("\n");
}

void printInGameMenu(int pos){
    system("cls");
    printMenu();
    printf("+----+--------------+\n");

    for(int i = 0; i < 3; i++){
        if(pos == i){
            printf("| \033[47m  \033[0m | ");
        } else {
            printf("|    | ");
        }
        switch(i){
        case 0:
            printf("Controls     |\n");
            break;
        case 1:
            printf("Restart game |\n");
            break;
        case 2:
            printf("Back to game |\n");
            break;
        }
    }

    printf("+----+--------------+\n\n");

    printf("Press Arrow Keys Up/Down to move selection\n");
    printf("Press ENTER / SPACE to select");
}

void inGameMenu(){
    int button; 
    int pos = 0;

    do{
        printInGameMenu(pos);
    
        button = _getch();

        if((button == KEY_ARROW_UP || button == KEY_W) && pos > 0){
            pos--;
        } else if ((button == KEY_ARROW_DOWN || button == KEY_S) && pos < 2){
            pos++;
        } else if (button == KEY_ENTER || button == KEY_SPACE){
            switch(pos){
                case 0:
                    printControls();
                    break;
                case 1:
                    //not yet finished
                    break;
                case 2:
                    pos = -1;
                    break;
            }
        }
    } while(pos != -1);
}

void printControls(){
    int button;

    system("cls");

    printf("Controls: \n\n");
    printf("| Action             | first key | secondary key   |\n");
    printf("+--------------------+-----------+-----------------+\n");
    printf("| Move up:           |     W     |  ARROW key up   |\n");
    printf("| Move down:         |     S     | ARROW key down  |\n");
    printf("| Move left:         |     A     | ARROW key left  |\n");
    printf("| Move right:        |     D     | ARROW key right |\n");
    printf("| Destroy Field:     |   ENTER   |      SPACE      |\n");
    printf("| Place flag:        |     F     |                 |\n");
    printf("| En/Disable Cheats: |     C     |                 |\n");

    printf("\nPress ENTER / SPACE to return to the menu");

    do{
        button = _getch();
    } while(button != KEY_ENTER && button != KEY_SPACE);
}