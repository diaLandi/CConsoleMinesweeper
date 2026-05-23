#ifndef PRINTING
#define PRINTING

#include <conio.h>
#include <stdio.h>
#include <windows.h>

#define GAME_FIELD_HEIGHT 16
#define GAME_FIELD_LEN 16

#define MINE_COUNT 40


#define KEY_ENTER 13
#define KEY_SPACE 32

#define KEY_ARROW_UP 72
#define KEY_ARROW_DOWN 80
#define KEY_ARROW_LEFT 75
#define KEY_ARROW_RIGHT 77

#define KEY_A 97
#define KEY_C 99
#define KEY_D 100
#define KEY_F 102
#define KEY_M 109
#define KEY_S 115
#define KEY_W 119

void printFieldUser(char gameField[GAME_FIELD_LEN][GAME_FIELD_HEIGHT], int cursorPositionX, int cursorPositionY, int cheat);

void printMinesweeper();
void printYouWin();
void inGameMenu();
void printGameOver();
void printMenu();

void printInGameMenu(int pos);
void printControls();

#endif