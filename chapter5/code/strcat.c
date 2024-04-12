#include <stdio.h>
#include <string.h>

void strGato(char *s, char *t);

int main() {
    char s[] = "hello";
    char t[] = " world";
    strGato(s, t);
    printf("%s\n", s);
    return 0;
}

void strGato(char *s, char *t) {
    /*
    increment s until null
    then set s to t until t is done.
    */
    while (*s != '\0')
        s++;
    while ((*s++ = *t++) != '\0')
        ;
}



/*
// strcat:  concatenate t to end of s; s must be big enough
void strcat(char s[], char t[]) {
    int i, j;

    i = j = 0;
    while (s[i] != '\0') // find end of s
        i++;
    // copy t
    while ((s[i++] = t[j++]) != '\0')
        ;
}

*/
