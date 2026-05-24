#ifndef INIT
#define INIT

#include <conio.h>
#include <locale.h>
#include <windows.h>
#include <stdio.h>
#include <time.h>

#include "printing.h"

void initRand();
void enableAnsi();
void init_utf8_konsole();

int countBombs(int gameLength, int gameHeight, char gameField[gameLength][gameHeight], int indexX, int indexY, int sizeX, int sizeY);
void generateField(int gameLength, int gameHeight, char gameField[gameLength][gameHeight], int firstPositionX, int firstPositionY);
void firstInitArray(int gameLength, int gameHeight, char gameField[gameLength][gameHeight], char initingLetter);
#endif