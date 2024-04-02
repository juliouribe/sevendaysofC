 #include <stdio.h>
 /* copy input to output; 1st version */
void main() {
    int c;
    long nc;
    nc = 0; 
    while ((c = getchar()) != EOF) {
        putchar(c);
        printf("%ld\n", c);
        ++nc;
        if (c == '\n'){
            printf("%ld\n", nc);
            nc = 0;
        }
    }
    printf("goodbye world\n");
} 