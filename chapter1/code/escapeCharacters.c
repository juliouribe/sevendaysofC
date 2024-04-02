#include <stdio.h>

int main(){
    int c;
    while(c != EOF){
        c = getchar();
        if(c == '\t')
            printf("\\t", c);
        else if(c == '\b'){
            printf("\\b", c);}
        else if(c == '\\')
            printf("\\\\", c);            
        else
            putchar(c);
    }
    return 0;
}