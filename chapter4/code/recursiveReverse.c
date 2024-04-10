#include <stdio.h>
#include <string.h>

char s[] = "racecars";

void reverse(int, int);

int main(){
    reverse(0, strlen(s) - 1);
    printf(s);
    printf("\n");
    return 0;
}

void reverse(int left, int right){
    if (left >= right) return;
    int temp = s[left];
    s[left] = s[right];
    s[right] = temp;
    reverse(left + 1, right - 1);
}

/*
    
*/

