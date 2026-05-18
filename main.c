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

int countBombs(char gameField[GAME_FIELD_LEN][GAME_FIELD_HEIGHT], int indexX, int indexY, int sizeX, int sizeY){
    int counter = 0;
    
    if(indexX > sizeX || indexX < 0 || indexY > sizeY || indexY < 0){
        return -1;
    }
    
    for(int i = -1; i < 2; i++){
        for(int j = -1; i < 2; j++){
            if(indexX + i >= 0 && indexX + i < sizeX){
                if(indexY + j >= 0 && indexY + j < sizeY){
                    if(gameField[indexX + i][indexY + j]){
                        counter++;
                    }
                }
            }
        }
    }
    
    return counter;
}

void moveInField(char gameField[GAME_FIELD_LEN][GAME_FIELD_HEIGHT], int positionX, int positionY){
    int button;

    do{
        system("cls");
        printFieldUser(gameField, positionX, positionY);
        button = _getch();

        if(button == ARROW_LEFT && positionX > 0){
            positionX--;
        } else if(button == ARROW_UP && positionY > 0){
            positionY--;
        } else if(button == ARROW_RIGHT && positionX < GAME_FIELD_LEN - 1){
            positionX++;
        } else if(button == ARROW_DOWN && positionY < GAME_FIELD_HEIGHT - 1){
            positionY++;
        }

    } while(button != ENTER_KEY);
}

void firstMove(char gameField[GAME_FIELD_LEN][GAME_FIELD_HEIGHT]){
    system("cls");

    printMinesweeper();
    moveInField(gameField, GAME_FIELD_LEN / 2, GAME_FIELD_HEIGHT / 2);
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
        fieldSize = 40;
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

    firstInitArray(gameField, '?', GAME_FIELD_LEN, GAME_FIELD_HEIGHT);

    firstMove(gameField);
}