#include <stdio.h>
int Power(int , int );

int main() {
    int test = Power(2,5);
    printf("%d",test);
    return 0;
}

int Power(int num, int PowerNum){
    if (PowerNum == 1){
        return num;
    }
    return num * Power(num,PowerNum-1);
}