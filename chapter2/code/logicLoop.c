#include <stdio.h>

int main()
{
    int i, lim, c, count;
    lim = 5;
    char s[lim];
    // test
    // for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
    //    s[i] = c;
    // printf("\n");
    // second time
    i = 0;
    while (c != EOF)
    {
        c = getchar();
        if (c != '\n')
        {
            s[i] = c;
            ++i;
            ++count;
        }
        if (i == lim)
            break;
    }
    printf("\n");
    for (i = 0; i < count; ++i)
    {
        putchar(s[i]);
    }
    printf("\n");
    return 0;
}
