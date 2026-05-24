#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <windows.h>

#include "printing.h"
#include "init.h"

void placeFlag(int gameLength, int gameHeight, char gameField[gameLength][gameHeight], int posX, int posY){
    if(gameField[posX][posY] <= 9){
        gameField[posX][posY] += 10;
    } else if (gameField[posX][posY] >= 10 && gameField[posX][posY] <=19){
        gameField[posX][posY] -= 10;
    }
}

void inGameMenu(){
    int button; 
    int pos = 0;

    do{
        printInGameMenu(pos);
    
        button = _getch();

        if((button == KEY_ARROW_UP || button == KEY_W) && pos > 0){
            pos--;
        } else if ((button == KEY_ARROW_DOWN || button == KEY_S) && pos < 3){
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
                case 3:
                    //not yet finished
                    break;
            }
        }
    } while(pos != -1);
}

void moveInField(int gameLength, int gameHeight, char gameField[gameLength][gameHeight], int *positionX, int *positionY, int* cheat){
    int button;

    do{
        system("cls");
        printMinesweeper();
        
        printFieldUser(gameLength, gameHeight, gameField, *positionX, *positionY, *cheat);
        printf("\n\nPress \033[1mM\033[0m for Menu");
        button = _getch();

        if((button == KEY_ARROW_LEFT || button == KEY_A) && *positionX > 0){
            (*positionX)--;
        } else if((button == KEY_ARROW_UP || button == KEY_W) && *positionY > 0){
            (*positionY)--;
        } else if((button == KEY_ARROW_RIGHT || button == KEY_D) && *positionX < gameLength - 1){
            (*positionX)++;
        } else if((button == KEY_ARROW_DOWN || button == KEY_S) && *positionY < gameHeight - 1){
            (*positionY)++;
        } else if(button == KEY_F){
            placeFlag(gameLength, gameHeight, gameField, *positionX, *positionY);
        } else if(button == KEY_C){
            if(*cheat == 0){
                *cheat = 1;
            } else {
                *cheat = 0;
            }
        } else if(button == KEY_M){
            inGameMenu();
        }

    } while(button != KEY_ENTER && button != KEY_SPACE);
}

void refreshBombsOnField(int gameLength, int gameHeight, char gameField[gameLength][gameHeight]){
    for(int i = 0; i < gameLength; i++){
        for(int j = 0; j < gameLength; j++){
            if(gameField[j][i] != 9){
                int cnt = countBombs(gameLength, gameHeight, gameField, j, i, gameLength, gameHeight);

                if(gameField[j][i] == '0'){
                    gameField[j][i] = (char)(cnt + '0');
                } else if(gameField[j][i] == 0){
                    gameField[j][i] = cnt;
                }
            }
        }
    }
}

void firstMove(int gameLength, int gameHeight, char gameField[gameLength][gameHeight], int* valuePosX, int* valuePosY, int* cheat){
    *valuePosX = gameLength / 2 - 1;
    *valuePosY = gameLength / 2 - 1;

    system("cls");

    printMinesweeper();
    moveInField(gameLength, gameHeight, gameField, valuePosX, valuePosY, cheat);

    generateField(gameLength, gameHeight, gameField, *valuePosX, *valuePosY);

    system("cls");
    gameField[*valuePosX][*valuePosY] = '0';
}

void findFoundFields(int gameLength, int gameHeight, char gameField[gameLength][gameHeight], int sizeX, int sizeY){
    int retry;
    do{
        retry = 0;

        for(int i = 0; i < sizeX; i++){
            for(int j = 0; j < sizeY; j++){
                if(gameField[i][j] == '0'){
                    for(int k = -1; k < 2; k++){
                        for(int l = -1; l < 2; l++){
                            if(k != 0 || l != 0){
                                if(i + k < sizeX && i + k >= 0 && j + l < sizeY && j + l >= 0){
                                    if(gameField[i + k][j + l] < 9){
                                        gameField[i + k][j + l] += '0';
                                        retry = 1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }while(retry == 1);
}

int checkWin(int gameLength, int gameHeight, char gameField[gameLength][gameHeight], int sizeX, int sizeY, int mineCount){
    int counter = 0;
    for(int i = 0; i < sizeX; i++){
        for(int j = 0; j < sizeY; j++){
            if(gameField[i][j] >= '0' && gameField[i][j] <= '8'){
                counter++;
            }
        }
    }
    if(counter >= ((sizeX * sizeY) - mineCount)){
        return 2;
    } else {
        return 0;
    }
}

int revealField(int gameLength, int gameHeight, char gameField[gameLength][gameHeight], int posX, int posY, int sizeX, int sizeY, int mineCount){
    if(gameField[posX][posY] < 9){
        gameField[posX][posY] += '0';
        findFoundFields(gameLength, gameHeight, gameField, sizeX, sizeY);
        if(checkWin(gameLength, gameHeight, gameField, sizeX, sizeY, mineCount) == 2){
            return 2;
        } else {
            return 0;
        }
    } else if (gameField[posX][posY] >= 10 && gameField[posX][posY] < 19){
        gameField[posX][posY] -= 10;
        gameField[posX][posY] += '0';
        findFoundFields(gameLength, gameHeight, gameField, sizeX, sizeY);
        if(checkWin(gameLength, gameHeight, gameField, sizeX, sizeY, mineCount) == 2){
            return 2;
        } else {
            return 0;
        }
    } else if(gameField[posX][posY] == 9){
        return 1;
    } else if (gameField[posX][posY] >= '0'){
        return 0;
    }
    return -1;
}

void 
game(int gameLength, int gameHeight, char gameField[gameLength][gameHeight], int minecount){
    int posX = -1, posY = -1;
    int cheat = 0;
    int status = 0;

    firstInitArray(gameLength, gameHeight, gameField, 0);

    firstMove(gameLength, gameHeight, gameField, &posX, &posY, &cheat);
    
    refreshBombsOnField(gameLength, gameHeight, gameField);
    findFoundFields(gameLength, gameHeight, gameField, gameLength, gameHeight);
    
    do{
        moveInField(gameLength, gameHeight, gameField, &posX, &posY, &cheat);
        status = revealField(gameLength, gameHeight, gameField, posX, posY, gameLength, gameHeight, minecount);
    }while(status == 0);

    system("cls");

    if(status == 1){
        printGameOver();
    } else if (status == 2) {
        printYouWin();
    }
}

int startMenu(int* sizeX, int* sizeY, int* minecount, int* pos){
    int button; 
    *pos = 0;
    int quit = 0;

    do{
        printStartMenu(*pos);
        button = _getch();

        if((button == KEY_ARROW_UP || button == KEY_W) && *pos > 0){
            (*pos)--;
        } else if ((button == KEY_ARROW_DOWN || button == KEY_S) && *pos < 4){
            (*pos)++;
        } else if (button == KEY_ENTER || button == KEY_SPACE){
            switch(*pos){
                case 0:
                    *sizeX = 10;
                    *sizeY = 8;
                    *minecount = 10;
                    *pos = -10;
                    break;
                case 1:
                    *sizeX = 18;
                    *sizeY = 14;
                    *minecount = 40;
                    *pos = -11;
                    break;
                case 2:
                    *sizeX = 24;
                    *sizeY = 20;
                    *minecount = 99;
                    *pos = -12;
                    break;
                case 3:
                    printControls();
                    break;
                case 4:
                    quit = 1;
                    *pos = -1;
                    break;
            }
        }
    } while(*pos > -1);
    
    return quit;
}

int main(){
    initRand();
    enableAnsi();
    init_utf8_konsole();

    int quit, pos;

    int fieldLength, fieldHeight;
    int minecount;
    
    do{
        quit = startMenu(&fieldLength, &fieldHeight, &minecount, &pos);
        char gameField[fieldLength][fieldHeight];

        if (pos >= -10 && pos <= -12){
            game(fieldLength, fieldHeight, gameField, minecount);
        }

    }while(quit != 1);

    return 0;
}
