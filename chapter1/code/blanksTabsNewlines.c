#include <stdio.h>

int main(){
    int c;
    int b, t, n;
    b = t = n = 0;
    while(c != EOF){
        c = getchar();
        if(c == ' ')
            b++;
        else if(c == '\t')
            t++;
        else if(c == '\n')
            n++;
    }
    printf("\n%d\n", b);
    printf("%d\n", t);
    printf("%d\n", n);
    return 0;
}