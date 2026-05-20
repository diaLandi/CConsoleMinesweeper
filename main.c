#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>

#include "printing.h"
#include "init.h"

int countBombs(char gameField[GAME_FIELD_LEN][GAME_FIELD_HEIGHT], int indexX, int indexY, int sizeX, int sizeY){
    int counter = 0;

    if(indexX < 0 || indexX >= sizeX || indexY < 0 || indexY >= sizeY){
        return -1;
    }

    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            int x = indexX + i;
            int y = indexY + j;

            if(x < 0 || x >= sizeX || y < 0 || y >= sizeY){
                continue;
            }
            if(i == 0 && j == 0){
                continue;
            }
            if(gameField[x][y] == '9'){
                counter++;
            }
        }
    }

    return counter;
}

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
            if(gameField[j][i] != '9'){
                gameField[j][i] = countBombs(gameField, j, i, GAME_FIELD_LEN, GAME_FIELD_HEIGHT) + '0';
            }
        }
    }
}

void firstMove(char gameField[GAME_FIELD_LEN][GAME_FIELD_HEIGHT]){
    int valuePosX = GAME_FIELD_LEN / 2 - 1;
    int valuePosY = GAME_FIELD_HEIGHT / 2 - 1;
    int *positionX = &valuePosX;
    int *positionY = &valuePosY;

    system("cls");

    printMinesweeper();
    moveInField(gameField, positionX, positionY);

    generateField(gameField, *positionX, *positionY);

    system("cls");
    gameField[*positionX][*positionY] = '0';
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

int main(){
    srand(time(NULL));
    char gameField[GAME_FIELD_LEN][GAME_FIELD_HEIGHT];
    int lost = 0;
    enableAnsi();

    firstInitArray(gameField, '?', GAME_FIELD_LEN, GAME_FIELD_HEIGHT);

    firstMove(gameField);

    printFieldUser(gameField, -1, -1);
    refreshBombsOnField(gameField);
    
    do{
        printFieldUser(gameField, -1, -1);

        lost = 1; //later only after move, if on bomb
    }while(lost == 0);
}