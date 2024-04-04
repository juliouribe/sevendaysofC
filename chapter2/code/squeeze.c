#include <string.h>
#include <stdio.h>

// void squeeze(char[], int);
void squeeze(char[], char[]);


int main()
{
    char s1[] = "ABC";
    char s2[] = "EDC";
    squeeze(s1,s2);
    for (int i = 0; i < strlen(s1); ++i)
        putchar(s1[i]);
    printf("\n");
    return 0;
}

// void squeeze(char s[], int c)
// {
//     int i, j;
//     for (i = j = 0; s[i] != '\0'; i++) {
//         if (s[i] != c)
//         s[j++] = s[i];
//         s[j] = '\0';
//     }
// }

void squeeze(char s1[], char s2[]){
    for(int i = 0; s1[i] != '\0' ; i++){
        if( s1[i] == s2[i] )
            s1[i] = '\0';
    }
}