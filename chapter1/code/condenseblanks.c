#include <stdio.h>

#define TRUE 1
#define FALSE 0

int main(){
    int c;
    int s;
    while(c != EOF){
        c = getchar();
        if(c == ' '){
            if(s != TRUE) {
                putchar(c);
                s = TRUE;
            }
        } else {
            putchar(c);
            s = FALSE;
        }
    }
    return 0;
}