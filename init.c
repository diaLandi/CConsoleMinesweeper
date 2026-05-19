#include <conio.h>
#include <locale.h>
#include <windows.h>

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