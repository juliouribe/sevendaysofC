#include <stdio.h>
#include <string.h>

#define ASCII_LIMIT 128

void expand(char[], char[]);

int main()
{
    // char s1[] = "a-z0-9A-Z";
    // when it's 8 len, it gets weird.
    char s1[] = "0-7";
    char s2[ASCII_LIMIT];
    expand(s1, s2);
    printf("%s\n", s2);
    return 0;
}

// Expand s1 and fill in s2
void expand(char s1[], char s2[])
{
    int prev, next, i, j, c;
    prev = next = '\0';
    j = 0;
    for (i = 0; i < strlen(s1); i++) {
        c = s1[i];
        if (c == '-') {
            if (prev != '\0'){
                while (next == '\0') {
                    ++i;
                    c = s1[i];
                    if (c != '-') {
                        next = c;
                    }
                }
                while (prev < next) {
                    ++prev;
                    s2[j] = prev;
                    ++j;
                }
                next = '\0';
            }
        }
        else {
            s2[j] = prev = c;
            ++j;
        }
    }
}
