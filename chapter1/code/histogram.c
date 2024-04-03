#include <stdio.h>

#define MAXWORDS 100

int main()
{
    int c;
    int s;
    int count;
    int wordCounts[MAXWORDS];
    int idx;
    int state;

    count = 0;
    state = 0;
    idx = 0;
    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\n' && c != '\t') {
            ++count;
            state = 1;
        }
        else
            // State 1 means we were on a word, state 0 means we're on spaces.
            if (state == 1) {
                wordCounts[idx] = count;
                count = 0;
                state = 0;
                ++idx;
            }
    }
    // Print out >>>
    int i, j;
    for (i = 0; i < idx; i++) {
        for (j = 0; j < wordCounts[i]; j++)
            printf(">");
        printf("\n");
    }
    return 0;
}
