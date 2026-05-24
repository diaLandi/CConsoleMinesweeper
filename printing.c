#include "printing.h"

void printFieldUser(int gameLength, int gameHeight, char gameField[gameLength][gameHeight], int cursorPositionX, int cursorPositionY, int cheat){
    printf("+---------------------------------------------------------------+\n");

    for(int i = 0; i < gameLength; i++){
        for(int j = 0; j < gameLength; j++){
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
            if(j == gameLength - 1){
                printf("|\n");
            }
        }

        if(i < gameLength - 1){
            printf("|");
            for(int j = 0; j < gameLength - 1; j++){
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
    printf(" \\$$    $$ \\$$    $$| $$ | $$ | $$ \\$$     \\       \\$$    $$   \\$$$    \\$$     \\| $$      \n");
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

    for(int i = 0; i < 4; i++){
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
        case 3:
            printf("Quit game    |\n");
            break;
        }
    }

    printf("+----+--------------+\n\n");

    printf("Press Arrow Keys Up/Down to move selection\n");
    printf("Press ENTER / SPACE to select");
}

void printControls(){
    int button;

    system("cls");

    printf("Controls: \n\n");
    printf("| Action             | first key | secondary key   |\n");
    printf("+--------------------+-----------+-----------------+\n");
    printf("| Move up:           |     W     |  arrow key up   |\n");
    printf("| Move down:         |     S     | arrow key down  |\n");
    printf("| Move left:         |     A     | arrow key left  |\n");
    printf("| Move right:        |     D     | arrow key right |\n");
    printf("| Destroy Field:     |   ENTER   |      SPACE      |\n");
    printf("| Place flag:        |     F     |                 |\n");
    printf("| En/Disable Cheats: |     C     |                 |\n");

    printf("\nPress ENTER / SPACE to return to the menu");

    do{
        button = _getch();
    } while(button != KEY_ENTER && button != KEY_SPACE);
}

void printStartMenu(int pos){
    system("cls");
    printMinesweeper();
    printf("\n\n");

    for(int i = 0; i < 5; i++){
        if(pos == i){
            printf("\033[47m");
        }

        switch (i){
            case 0:
                printf("Play Game Mode: easy\033[0m\n\n");
                break;
            case 1:
                printf("Play Game Mode: medium\033[0m\n\n");
                break;
            case 2:
                printf("Play Game Mode: hard\033[0m\n\n");
                break;
            case 3:
                printf("Controls\033[0m\n\n");
                break;
            case 4:
                printf("Quit game\033[0m\n\n");
                break;
        }
    }

    printf("Press Arrow Keys Up/Down to move selection\n");
    printf("Press ENTER / SPACE to select");
}