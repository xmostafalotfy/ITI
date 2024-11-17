#include <stdio.h>

int main(){
char NumSum = 0;
do {
    int UserNum = 0;
    printf("\n Enter a num to sum");
    scanf("%d", &UserNum);
    NumSum += UserNum;

}while(NumSum < 100);
printf("\n your total : %d",NumSum);
return 0;
}
