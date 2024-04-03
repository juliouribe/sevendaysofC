#include <stdio.h>

#define MAXLENGTH 128 /* max length of alphabet */

int main() {
    int c;
    int counts[MAXLENGTH];
    for (int i = 0; i < MAXLENGTH; ++i)
        counts[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c != ' ' || c != '\n' || c != '\t') {
            ++counts[c];
        }
    }
    // iterate over all characters
    // include non-spaces
    // update counts in respective array index

    for (int i = 0; i < MAXLENGTH; ++i) {
        if (counts[i] > 0) {
            putchar(i);
            printf(": ");
            for (int j = 0; j < counts[i]; ++j)
                printf(">");
            printf("\n");
        }
    }
    return 0;
}
