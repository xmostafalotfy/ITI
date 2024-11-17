#include <stdio.h>
 int main(){
 int num = 18;
 float fnum = 8.9;
 char c = 'm' ;
 char nc ;
 printf("%d\n",num);
 printf("%f\n",fnum);
 printf("%c\n",c);
 printf("Enter a number\n");
 scanf("%c",&nc);
 printf("Char : %c, ASCII Code : %d\n",nc,nc);
 printf("Hex : %x, Oct : %o\n",num,num);
 return 0;
 }
