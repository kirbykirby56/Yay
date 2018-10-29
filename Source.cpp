#include<iostream>
#include<stdio.h>
#include<unistd.h>
#include<linux/ioctl.h>

struct winsize {
               unsigned short ws_row;
               unsigned short ws_col;
               unsigned short ws_xpixel;   /* unused */
               unsigned short ws_ypixel;   /* unused */
           };

int main() {
short consoleCharsX, consoleCharsY;
struct winsize siz;
consoleCharsX = consoleCharsY = 0;
ioctl(STDOUT_FILENO, TIOCGWINSZ, &siz);

}
