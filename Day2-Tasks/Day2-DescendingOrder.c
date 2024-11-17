#include <stdio.h>

int main(){
for (int i = 10 ; i >= 1; i--){
    for (int j = 1 ; j <= 10; j++){
        printf("\n %d * %d = %d",i,j,i*j);
    }
    printf("\n***********************************************************");
}
return 0;
}
