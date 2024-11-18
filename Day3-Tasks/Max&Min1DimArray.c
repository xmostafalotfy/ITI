#include <stdio.h>
#define SIZE 100
int main() {
    int arr[SIZE] = {0}, LoopExit = 0, UserSize = 0;
    while(LoopExit == 0){
        printf("Enter array size(should be less than 100) : ");
        scanf("%d",&UserSize);
        if (UserSize < SIZE){
            LoopExit = 1;
        }
    }
    
    int Max = 0, Min = 0;
    for (int i =0; i < UserSize; i++){
        printf("Enter num %d : ",i+1);
        scanf("%d",&arr[i]);
        if (i == 0){
            Min = arr[0];
            Max = arr[0];
        }else{
            if (arr[i] > Max){
                Max = arr[i];
            } else {
                if(arr[i] < Min){
                    Min = arr[i];
                }
            }
        }
    }
    printf("Max is : %d, Min is : %d",Max,Min);
    return 0;
}