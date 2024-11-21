#include <stdio.h>
#include <stdlib.h>



int mStrlen(char str[]){
    int i = 0;
    while(str[i] != '\0'){
        i++;
    }
    return i;
}


void mStrcat(char dest[], char src[],char len){
    int i = 0;
    while(src[i] != '\0' ){
        dest[len] = src[i]; \
        i++;
        len++;
    }
    dest[len] = '\0';
}


int mStrcmp(char str[], char str2[]){
    for(int i =0; str[i] != '\0'; i++){
    if(str[i] > str2[i]){
        return 1;
    }
    if(str[i] < str2[i]){
        return -1;
    }
}
return 0;
};


void mStrcpy(char dest[], char source[],int dest_size){

    int i = 0;
    if( mStrlen(source) < dest_size){
        for(i=0; source[i] != '\0'; i++){
            dest[i] = source[i];
        }
    dest[i] = '\0';
    }
    else{
        printf("Source should be bigger");
    }
};


void mLowerToUpper(char text[]){
int i = 0;
while(text[i] != '\0'){
    if (text[i] >= 97 && text[i] <= 122){
        text[i] -= 32;
    }
    i++;
}
};


void mUpperToLower(char text[]){
    int i =0;
    while(text[i] != '\0'){
        if(text[i] >= 65 && text[i] <= 90){
            text[i] = text[i] + 32;
        }
        i++;
    }
};