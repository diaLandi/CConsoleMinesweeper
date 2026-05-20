#include "init.h"

void enableAnsi(void){
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

void init_utf8_konsole() {
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8); 
        SetConsoleCP(CP_UTF8);
    #endif
}

void firstInitArray(char array[GAME_FIELD_LEN][GAME_FIELD_HEIGHT], char initingLetter, int sizeArrayX, int sizeArrayY){
    for(int i = 0; i < sizeArrayX; i++){
        for(int j = 0; j < sizeArrayY; j++){
            array[i][j] = initingLetter;
        }
    }
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