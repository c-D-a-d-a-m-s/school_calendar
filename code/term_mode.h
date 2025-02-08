#include <unistd.h>
#include <termios.h>
#include <stdlib.h>

#ifndef TERM_MODE_H
#define TERM_MODE_H

/*** functions ***/
void die();
void atExit();
void disableRawMode();
void enableRawMode();

#endif