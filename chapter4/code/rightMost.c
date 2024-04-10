#include <stdio.h>
#include <string.h>

int strindex(char[], int);

int main() {
    char name[] = "iLus";
    int idx = strindex(name, 'i');
    printf("%d\n", idx);
    return 0;
}

int strindex(char s[], int t) {
    int idx;
    for (idx = strlen(s) - 1; idx >=0; idx--)
        if (s[idx] == t)
            return idx;
    return -1;
}
