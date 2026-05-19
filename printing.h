#ifndef PRINTING
#define PRINTING

#define GAME_FIELD_HEIGHT 16
#define GAME_FIELD_LEN 16

#define ARROW_UP 72
#define ARROW_DOWN 80
#define ARROW_RIGHT 77
#define ARROW_LEFT 75
#define ENTER_KEY 13

void printFieldUser(char gameField[GAME_FIELD_LEN][GAME_FIELD_HEIGHT], int cursorPositionX, int cursorPositionY);
void printMinesweeper();

#endif