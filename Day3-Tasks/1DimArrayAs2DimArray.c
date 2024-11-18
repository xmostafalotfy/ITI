#include <stdio.h>
#define SIZE 100
int main() {
    int arr[SIZE] = {0}, UserSize = 0, UserRows = 0, UserCol = 0;
    int LoopExit = 0;
    while(LoopExit == 0){
        printf("\nEnter size of array : ");
        scanf("%d",&UserSize);
        printf("\nNum of Rows : ");
        scanf("%d",&UserRows);
    
        if (UserSize % UserRows == 0 && UserSize < SIZE){
            UserCol = UserSize / UserRows ;
            LoopExit = 1 ;
        } else {
            printf("Rows should be divisible by size & Size sould be less than 100");
        }
    }
    for (int row = 0; row < UserRows; row++){
        for(int col = 0; col < UserCol; col++){
            int index = row * UserCol + col;
                    printf("\nEnter element %d to be stored : ",index+1);
                    scanf("%d",&arr[index]);
                    
        } 
    }
    
        for (int row = 0; row < UserRows; row++){
            for(int col = 0; col < UserCol; col++){
                int index = row * UserCol + col;
                    printf("%d \t",arr[index]);
                    
            }
        printf("\n");
        }
    return 0;
}

