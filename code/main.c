/********************************/
/***          main.c          ***/
/********************************/

/*** includes ***/
#include "date.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void die(char* name, char* error_message) {
    /* crash program if error is encountered */
    fputs(name, stdout);
    fputs(": ", stdout);
    fputs(error_message, stdout);
    fputs("\n\n", stdout);
    exit(-1);
}

char* get_input() {
    const int TEMP_STR_BASE_SIZE = 10;
    int tempStrIdx = 0;
    char* tempStr = (char*)calloc(TEMP_STR_BASE_SIZE, sizeof(char));
    char c = '\0';
    while (c != '\n') {
        c = fgetc(stdin);
        if (c != '\n') {
            *(tempStr + tempStrIdx) = c;
            tempStrIdx++;
        }
        if (tempStrIdx % TEMP_STR_BASE_SIZE == TEMP_STR_BASE_SIZE -1) {
            tempStr = (char*)realloc(tempStr, (tempStrIdx + TEMP_STR_BASE_SIZE + 2) * sizeof(char));
            if (!tempStr) die("get_input", "Failed to reallocate memory.");
            memset(tempStr + tempStrIdx + 1, '\0', TEMP_STR_BASE_SIZE + 1);
        }
    }
    return tempStr;
}

/*** init ***/
int main() {
    char* testStr = get_input();
    fputs("\033[0;33m", stdout);
    fputs(testStr, stdout);
    fputs("\033[0m", stdout);

    free(testStr);

    return 0;
}