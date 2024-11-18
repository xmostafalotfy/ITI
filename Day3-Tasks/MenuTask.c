#include <stdio.h>
#include "conio.h"
#define UP 65
#define DOWN 66
#define WHITE printf("\033[0m")
#define PURPLE printf("\033[1;35m")
#define EXTEND 27
#define BACK 127
#define ENTER 10


void FirstLine(){
        clrscr();
        WHITE;
        printf("\033[%d;%dH Line : 1", 5,20);
        PURPLE;
        printf("\033[%d;%dH Menu", 10,20);
        WHITE;
        printf("\033[%d;%dH New", 15,20);
        printf("\033[%d;%dH Exit", 20,20);
        }
void SecondLine(){
        clrscr();
        WHITE;
        printf("\033[%d;%dH Line : 2", 5,20);
        printf("\033[%d;%dH Menu", 10,20);
        PURPLE;
        printf("\033[%d;%dH New", 15,20);
        WHITE;
        printf("\033[%d;%dH Exit", 20,20);
        }
void ThirdLine(){
        clrscr();
        WHITE;
        printf("\033[%d;%dH Line : 3", 5,20);
        printf("\033[%d;%dH Menu", 10,20);
        printf("\033[%d;%dH New", 15,20);
        PURPLE;
        printf("\033[%d;%dH Exit", 20,20);

}
int main(){

char Content = 0;
char Page=1;
FirstLine();

while(1){
char choice=getch();
    if(choice==EXTEND){
    choice=getch();
    choice=getch();
  }

switch(choice){
case UP:
    if (Content == 0){
        Page--;

        if (Page == 1)
            FirstLine();
        else if(Page == 2)
            SecondLine();
        else if(Page == 0){
            Page = 3;
            ThirdLine();
        }
    }
    break;

case DOWN:
    if (Content == 0){
        Page++;

        if (Page == 2)
            SecondLine();
        else if(Page == 3)
            ThirdLine();
        else if(Page == 4){
            Page = 1;
            FirstLine();
        }
    }
    break;

case ENTER:
    clrscr();
    if (Page == 1){
        PURPLE;
        printf("\033[%d;%dH Menu", 5,20);
        Content = 1;
    }else if(Page == 2){
        PURPLE;
        printf("\033[%d;%dH New", 5,20);
        Content = 1;
    }else{
        return 0;
    }
    break;

case BACK:
    if (Content == 1){
        clrscr();
        FirstLine();
        Content = 0;
        Page = 1;
    } else{
        clrscr();
        printf("Invalid Input (Up or Down to Back)");
    }
    break;

default:
    if(Content == 0){
        clrscr();
        printf("Invalid Input (Up or Down to Back)");
    }
    break;



}
}
}
