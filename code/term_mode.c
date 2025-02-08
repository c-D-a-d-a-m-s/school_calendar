#include "term_mode.h"

/*** data ***/
struct termios cookedMode;

/*** functions ***/
void die() {
    write(STDOUT_FILENO, "Whoops", 6);
    exit(-1);
}

void atExit() {
    if (write(STDOUT_FILENO, "\033[2J", 4) == -1) die();
    if (write(STDOUT_FILENO, "\x1b[H", 3) == -1) die();
    disableRawMode();
    exit(0);
}

void disableRawMode() {
    if (tcsetattr(STDIN_FILENO,TCSAFLUSH, &cookedMode) == -1) die();
}

void enableRawMode() {
    if (tcgetattr(STDIN_FILENO, &cookedMode) == -1) die();

    struct termios rawMode = cookedMode;

    rawMode.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP 
            | INLCR | IGNCR | ICRNL | IXON);
    rawMode.c_oflag &= ~(OPOST);
    rawMode.c_lflag &= ~(ECHO | ECHONL | ICANON | ISIG | IEXTEN);
    rawMode.c_cflag &= ~(CSIZE | PARENB);
    rawMode.c_cflag |= CS8;

    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &rawMode) == -1) die();
}