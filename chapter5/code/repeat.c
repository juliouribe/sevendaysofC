#include <stdio.h>

void repeat(char[], int);

int main(int argc, char *argv[]) {
    printf("%s\n", argv[0]);
    int times = *argv[2] - '0';
    // putchar(*argv[2]);
    // printf("%d\n", times);
    repeat(argv[1], times);
    return 0;
}

void repeat(char phrase[], int times) {
    for (int i = 0; i < times; ++i)
        printf("%s\n", phrase);
}
