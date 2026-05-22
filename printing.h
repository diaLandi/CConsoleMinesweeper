#ifndef PRINTING
#define PRINTING

#include <stdio.h>

#define GAME_FIELD_HEIGHT 16
#define GAME_FIELD_LEN 16

#define MINE_COUNT 40

#define ARROW_UP 72
#define ARROW_DOWN 80
#define ARROW_RIGHT 77
#define ARROW_LEFT 75
#define ENTER_KEY 13
#define KEY_C 99
#define KEY_F 102
#define KEY_H 104

void printFieldUser(char gameField[GAME_FIELD_LEN][GAME_FIELD_HEIGHT], int cursorPositionX, int cursorPositionY, int cheat);
void printMinesweeper();
void printYouWin();
void printGameOver();

#endif