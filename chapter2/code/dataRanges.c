#include <stdio.h>
#include <limits.h>
// https://www.tutorialspoint.com/c_standard_library/limits_h.htm

int main()
{
    printf("Range of signed CHAR: %d to %d\n", CHAR_MIN, CHAR_MAX);
    printf("Range of unsigned CHAR: %d to %d\n", 0, UCHAR_MAX);

    printf("Range of signed SHORT: %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("Range of unsigned SHORT: %d to %d\n", 0, USHRT_MAX);

    printf("Range of signed INT: %d to %d\n", INT_MIN, INT_MAX);
    printf("Range of unsigned INT: %d to %u\n", 0, UINT_MAX);

    printf("Range of signed LONG: %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("Range of unsigned LONG: %d to %lu\n", 0, ULONG_MAX);
    return 0;
}

/*
Signed means could be negative.
Unsigned means start at 0.

unsigned char limit range is 0 to
signed char limit range is - to

unsigned short limit range is 0 to
signed short limit range is - to

unsigned int limit range is 0 to
signed int limit range is - to

unsigned long limit range is 0 to
signed long limit range is - to

*/
