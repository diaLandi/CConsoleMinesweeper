#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <conio.h>

#include "printing.h"

#define MINE_COUNT 40
#define ARROW_UP 72
#define ARROW_DOWN 80
#define ARROW_RIGHT 77
#define ARROW_LEFT 75
#define ENTER_KEY 13

static void enableAnsi(void){
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;

    if(hOut == INVALID_HANDLE_VALUE){
        return;
    }

    if(!GetConsoleMode(hOut, &dwMode)){
        return;
    }

    SetConsoleMode(hOut, dwMode | ENABLE_PROCESSED_OUTPUT | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
}

int countBombs(char gameField[GAME_FIELD_LEN][GAME_FIELD_HEIGHT], int indexX, int indexY, int sizeX, int sizeY){
    int counter = 0;

    if(indexX < 0 || indexX >= sizeX || indexY < 0 || indexY >= sizeY){
        return -1;
    }

    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            int x = indexX + i;
            int y = indexY + j;

            if(x < 0 || x >= sizeX || y < 0 || y >= sizeY) continue;
            if(i == 0 && j == 0) continue; // don't count the center cell
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

void generateField(char gameField[GAME_FIELD_LEN][GAME_FIELD_HEIGHT], int firstPositionX, int firstPositionY){
    int randX;
    int randY;
    int index = 0;
    while(index < MINE_COUNT){
        randX = rand() % GAME_FIELD_LEN;
        randY = rand() % GAME_FIELD_HEIGHT;

        if(gameField[randX][randY] != '9' && !(randX == firstPositionX && randY == firstPositionY)){
            gameField[randX][randY] = '9';
            index++;
        }
    }
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

void firstInitArray(char array[GAME_FIELD_LEN][GAME_FIELD_HEIGHT], char initingLetter, int sizeArrayX, int sizeArrayY){
    for(int i = 0; i < sizeArrayX; i++){
        for(int j = 0; j < sizeArrayY; j++){
            array[i][j] = initingLetter;
        }
    }
}

int main(){
    srand(time(NULL));
    char gameField[GAME_FIELD_LEN][GAME_FIELD_HEIGHT];

    enableAnsi();

    firstInitArray(gameField, '?', GAME_FIELD_LEN, GAME_FIELD_HEIGHT);

    firstMove(gameField);

    printFieldUser(gameField, -1, -1);

    refreshBombsOnField(gameField);
    printFieldUser(gameField, -1, -1);
}