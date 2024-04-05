#include <stdio.h>
#include <string.h>

void escape(char[], char[]);

int main()
{
    char t[] = "this  is a\nstring";
    char s[strlen(t) * 2];
    escape(s, t);
    printf("%s\n", t);
    return 0;
}
/* s is empty, t original? */
void escape(char s[], char t[])
{
    char c;
    int j = 0;
    for (int i = 0; i < strlen(t); i++, ++j)
    {
        c = t[i];
        switch (c)
        {
        case '\n':
            s[j] = '\\';
            ++j;
            s[j] = 'n';
            break;
        case '\t':
            s[j] = '\\';
            ++j;
            s[j] = 't';
            break;
        default:
            s[j] = c;
            break;
        }
    }
}
