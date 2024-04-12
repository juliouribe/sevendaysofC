#include <stdio.h>
#include <string.h>

int strend(char *s, char *t);

int main(){
    char s[] = "abcdef";
    char t[] = "def";
    char g[] = "b";
    printf("%d\n", strend(s,t));
    printf("%d\n", strend(s,g));
    return 0;
}

int strend(char *s, char *t){
    char *g = t;
    while(*s != '\0') s++;
    while(*t != '\0') t++;
    do {
        s--;
        t--;
        if (*t != *s){
            return 0;
        } 
    } while(t != g);
    return 1;
}
