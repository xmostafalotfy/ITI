#include <stdio.h>

int main(){
    int x = 5,y = 6;

     x = x + y;
     y = x - y;
     x = x - y;
     printf("%d,%d",x,y);

     x = 5, y = 6;

     x = x * y;
     y = x / y;
     x = x / y;
     printf("%d,%d",x,y);

     x = 5, y = 6;

     x = x - y;
     y = x + y;
     x = y - x;
     printf("%d,%d",x,y);

     float yf = 4, xf = 6;

     xf = xf / yf;
     yf = xf * yf;
     xf = yf / xf;
     printf("%f,%f",xf,yf);

     x = 5, y = 6;

     x = x ^ y;
     y = x ^ y;
     x = x ^ y;
     printf("%d,%d",x,y);


    return 0;

}
