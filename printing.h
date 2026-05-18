#ifndef PRINTING
#define PRINTING

#define GAME_FIELD_HEIGHT 16
#define GAME_FIELD_LEN 16

void printFieldUser(char gameField[GAME_FIELD_LEN][GAME_FIELD_HEIGHT], int cursorPositionX, int cursorPositionY);
void printMinesweeper();

#endif