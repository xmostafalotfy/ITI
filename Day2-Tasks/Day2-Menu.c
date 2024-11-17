#include <stdio.h>

int main(){
int UserChoice = 0;
printf("Choose 1 item \n 1) Cheese Burger \n 2) Fried Chicken \n 3) Fries \n");
scanf(" %d",&UserChoice);
switch(UserChoice){
    case 1:
        printf("Cheese Burger");
        break;
    case 2:
        printf("Fried Chicken");
        break;
    case 3:
        printf("Fries");
        break;
    default:
        printf("out of menu");
        }
return 0;
}
