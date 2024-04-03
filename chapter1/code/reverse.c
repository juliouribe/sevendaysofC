#include <stdio.h>

#define MAXLENGTH 1000

char reverse(char[], int);
int len(char[]);

int main(){
    int c;
    int len = 0;
    char arr[MAXLENGTH];
    while((c = getchar()) != EOF){
        arr[len] = c;
        len++;
    }
    printf("\n");
    reverse(arr, len);
}

char reverse(char arr[], int len){
    for(len; len > 0; --len)
        putchar(arr[len-1]);
    printf("\n");
}