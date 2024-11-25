#include <stdio.h>
#include "conio.h"
#define RIGHT 67
#define LEFT 68
#define EXTEND 27
#define BACK 127
#define SIZE 100
#define DELETE 81 // F2
#define INSERT 80 // F1
#define END 70
#define HOME 72

int main() {
    char* content[SIZE] = {0};
    char** cursorPosition = content;
    char** currentPosition = content;
    char insertFlag = 0;

    while (1) {
        if (insertFlag == 0) {
            printf("\033[6 q");
        } else {
            printf("\033[4 q");
        }

        char ch = getch();
        if (ch == EXTEND) {
            if (!kbhit()) {
                clrscr();
                return 0;
            }
            ch = getch();
            ch = getch();
        }

        switch (ch) {
            case RIGHT:
                if (cursorPosition < currentPosition) {
                    cursorPosition++;
                }
                break;

            case END:
                cursorPosition = currentPosition;
                break;

            case HOME:
                cursorPosition = content;
                break;

            case LEFT:
                if (cursorPosition > content) {
                    cursorPosition--;
                }
                break;

            case INSERT:
                insertFlag = !insertFlag;
                break;

            case BACK:
                if (cursorPosition > content) {
                    for (char** ptr = cursorPosition - 1; ptr < currentPosition - 1; ptr++) {
                        *ptr = *(ptr + 1);
                    }
                    *(currentPosition - 1) = 0;
                    currentPosition--;
                    cursorPosition--;
                }
                break;

            case DELETE:
                if (cursorPosition < currentPosition) {
                    for (char** ptr = cursorPosition; ptr < currentPosition - 1; ptr++) {
                        *ptr = *(ptr + 1);
                    }
                    *(currentPosition - 1) = 0;
                    currentPosition--;
                }
                break;

            default:
                if (ch >= 32 && ch <= 126) {
                    if (cursorPosition == currentPosition) {
                        *cursorPosition = ch;
                        currentPosition++;
                        cursorPosition++;
                    } else {
                        if (insertFlag == 0) {
                            for (char** ptr = currentPosition; ptr > cursorPosition; ptr--) {
                                *ptr = *(ptr - 1);
                            }
                            *cursorPosition = ch;
                            currentPosition++;
                            cursorPosition++;
                        } else {
                            *cursorPosition = ch;
                            cursorPosition++;
                        }
                    }
                }
                break;
        }

        clrscr();
        for (char** ptr = content; ptr < currentPosition; ptr++) {
            printf("%c", *ptr);
        }

        printf("\033[;%dH", (cursorPosition - content) + 1);
    }

    return 0;
}
