#include "init.h"

void initRand(){
    srand(time(NULL));
}

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

void init_utf8_konsole(){
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8); 
        SetConsoleCP(CP_UTF8);
    #endif
}

int countBombs(int gameLength, int gameHeight, char gameField[gameLength][gameHeight], int indexX, int indexY, int sizeX, int sizeY){
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
            if(gameField[x][y] == 9){
                counter++;
            }
        }
    }

    return counter;
}

void firstInitArray(int gameLength, int gameHeight, char gameField[gameLength][gameHeight], char initingLetter){
    for(int i = 0; i < gameLength; i++){
        for(int j = 0; j < gameHeight; j++){
            gameField[i][j] = initingLetter;
        }
    }
}

void generateField(int gameLength, int gameHeight, char gameField[gameLength][gameHeight], int firstPositionX, int firstPositionY, int minecount){
    int randX, randY;
    int index = 0;
    while(index < minecount){
        randX = rand() % gameLength;
        randY = rand() % gameLength;

        if(gameField[randX][randY] != 9 && !(randX >= firstPositionX - 1 && randX <= firstPositionX + 1 && randY >= firstPositionY - 1 && randY <= firstPositionY + 1)){
            gameField[randX][randY] = 9;
            index++;
        }
    }
}