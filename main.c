#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#define GAME_FIELD_HEIGHT 16
#define GAME_FIELD_LEN 16
#define MINE_COUNT 40

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

void printFieldUser(char gameField[GAME_FIELD_LEN][GAME_FIELD_HEIGHT]){
    printf("+-------------------------------+\n");

    for(int i = 0; i < GAME_FIELD_HEIGHT; i++){
        for(int j = 0; j < GAME_FIELD_LEN; j++){
            printf("| %c ", gameField[j][i]);
            if(j = GAME_FIELD_LEN - 1){
                printf("|\n");
            }
        }

        if(i < GAME_FIELD_HEIGHT - 1){
            printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
        }
    }

    printf("+-------------------------------+\n");
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

void firstMove(char gameField[GAME_FIELD_LEN][GAME_FIELD_HEIGHT]){
    
}

int main(){
    char gameField[GAME_FIELD_LEN][GAME_FIELD_HEIGHT] = {'0'};

    printFieldUser(gameField);
}