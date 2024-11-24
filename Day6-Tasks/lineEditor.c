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

int main(){
    char content[SIZE] ={0};
    char cursorPosition = 0;
    char currentSize = 0;
    char insertFlag = 0;


    while(1){
        if(insertFlag == 0){
            printf("\033[6 q");

        }
        else{
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


        switch (ch)
        {
        case RIGHT :
            cursorPosition++;
            if(cursorPosition >= currentSize){
                cursorPosition = currentSize;
            }
            break;

        case END :
            cursorPosition = currentSize;
            break;

        case HOME :
            cursorPosition = 0;
            break;

        case LEFT :
            cursorPosition--;
            if(cursorPosition <= 0){
                cursorPosition = 0;
            }
            break;

        case INSERT:
            if(insertFlag == 0){
                insertFlag = 1;
            }
            else{
                insertFlag = 0;
            }
            break;

        case BACK:
            if(cursorPosition == 0){
                break;
            }
            for (int i = cursorPosition; i < currentSize; i++) {
                        content[i-1] = content[i];
            }
            content[currentSize] = '\0';
            currentSize--;
            cursorPosition--;
            break;

        case DELETE:

            if(cursorPosition == currentSize){
                break;
            }
            for (int i = cursorPosition; i < currentSize; i++) {
                        content[i] = content[i+1];
            }
            content[currentSize] = '\0';
            currentSize--;
            break;

        default:
        if(ch >= 32 && ch <= 126){
            if (currentSize == cursorPosition){
                content[currentSize] = ch;
                currentSize++;
                cursorPosition++;
            }
            else{
                    if(insertFlag == 0){

                for (int i = currentSize; i > cursorPosition; i--) {
                        content[i] = content[i - 1];
                    }

                content[cursorPosition] = ch;
                currentSize++;
                cursorPosition++;
            }
            else{
                content[cursorPosition] = ch;
                currentSize++;
                cursorPosition++;
                }
            }

            break;
        }
        }

        clrscr();
        for(int i = 0;i<currentSize;i++){
            printf("%c",content[i]);
        }

        printf("\033[;%dH", cursorPosition+1);
}

    return 0;
}
