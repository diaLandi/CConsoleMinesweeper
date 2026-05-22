#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>

#include "printing.h"
#include "init.h"

void moveInField(char gameField[GAME_FIELD_LEN][GAME_FIELD_HEIGHT], int *positionX, int *positionY){
    int button;

    do{
        system("cls");
        printMinesweeper();
        
        printFieldUser(gameField, *positionX, *positionY);
        button = _getch();

        if(button == ARROW_LEFT && *positionX > 0){
            (*positionX)--;
        } else if(button == ARROW_UP && *positionY > 0){
            (*positionY)--;
        } else if(button == ARROW_RIGHT && *positionX < GAME_FIELD_LEN - 1){
            (*positionX)++;
        } else if(button == ARROW_DOWN && *positionY < GAME_FIELD_HEIGHT - 1){
            (*positionY)++;
        }

    } while(button != ENTER_KEY);
}

void refreshBombsOnField(char gameField[GAME_FIELD_LEN][GAME_FIELD_HEIGHT]){
    for(int i = 0; i < GAME_FIELD_HEIGHT; i++){
        for(int j = 0; j < GAME_FIELD_LEN; j++){
            if(gameField[j][i] != 9){
                int cnt = countBombs(gameField, j, i, GAME_FIELD_LEN, GAME_FIELD_HEIGHT);

                if(gameField[j][i] == '0'){
                    gameField[j][i] = (char)(cnt + '0');
                } else if(gameField[j][i] == 0){
                    gameField[j][i] = cnt;
                }
            }
        }
    }
}

void firstMove(char gameField[GAME_FIELD_LEN][GAME_FIELD_HEIGHT], int* valuePosX, int* valuePosY){
    *valuePosX = GAME_FIELD_LEN / 2 - 1;
    *valuePosY = GAME_FIELD_HEIGHT / 2 - 1;

    system("cls");

    printMinesweeper();
    moveInField(gameField, valuePosX, valuePosY);

    generateField(gameField, *valuePosX, *valuePosY);

    system("cls");
    gameField[*valuePosX][*valuePosY] = '0';
}

int menu(){
    int fieldSize;

    system("cls");
    printf("How hard should the Game be?\n");
    printf("Intermediate (1)\n\n");
    printf("Your choice");
    
    do{
        scanf("%d", &fieldSize);
    } while(fieldSize != 1);
    
    switch (fieldSize) {
    case 1:
        fieldSize = 16;
        break;
    }

    return fieldSize;
}

void findFoundFields(char array[GAME_FIELD_LEN][GAME_FIELD_HEIGHT], int sizeX, int sizeY){
    int retry;
    do{
        retry = 0;

        for(int i = 0; i < sizeX; i++){
            for(int j = 0; j < sizeY; j++){
                if(array[i][j] == '0'){
                    for(int k = -1; k < 2; k++){
                        for(int l = -1; l < 2; l++){
                            if(k != 0 || l != 0){
                                if(i + k < sizeX && i + k >= 0 && j + l < sizeY && j + l >= 0){
                                    if(array[i + k][j + l] < 9){
                                        array[i + k][j + l] += '0';
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

int revealField(char gameField[GAME_FIELD_LEN][GAME_FIELD_HEIGHT], int posX, int posY, int sizeX, int sizeY){
    if(gameField[posX][posY] < 9){
        gameField[posX][posY] += '0';
        findFoundFields(gameField, sizeX, sizeY);
        return 0;
    } else if(gameField[posX][posY] == 9){
        gameField[posX][posY] += '0';
        return 1;
    }
}

int main(){
    srand(time(NULL));

    char gameField[GAME_FIELD_LEN][GAME_FIELD_HEIGHT];
    int lost = 0;
    int posX = -1, posY = -1;

    enableAnsi();

    firstInitArray(gameField, 0, GAME_FIELD_LEN, GAME_FIELD_HEIGHT);

    firstMove(gameField, &posX, &posY);
    
    refreshBombsOnField(gameField);
    findFoundFields(gameField, GAME_FIELD_LEN, GAME_FIELD_HEIGHT);
    
    do{
        moveInField(gameField, &posX, &posY);
        lost = revealField(gameField, posX, posY, GAME_FIELD_LEN, GAME_FIELD_HEIGHT);
    }while(lost == 0);
}