#ifndef INIT
#define INIT

#include <conio.h>
#include <locale.h>
#include <windows.h>

#include "printing.h"

void enableAnsi(void);
void init_utf8_konsole();

void generateField(char gameField[GAME_FIELD_LEN][GAME_FIELD_HEIGHT], int firstPositionX, int firstPositionY);
void firstInitArray(char array[GAME_FIELD_LEN][GAME_FIELD_HEIGHT], char initingLetter, int sizeArrayX, int sizeArrayY);

#endif