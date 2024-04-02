 #include <stdio.h>
 /* copy input to output; 1st version */
int main() {
    int c;
    long nc;
    nc = 0;
    while ((c = getchar()) != EOF) {
        putchar(c);
        // printf("%d\n", c);
        if (c != '\n')
            ++nc;
        else {
            printf("%ld\n", nc);
            nc = 0;
        }
    }
    printf("goodbye world\n");
    // printf("%d\n", EOF);
    // printf("%d\n", c);
    return 0;
}
