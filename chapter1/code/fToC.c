#include <stdio.h>

#define LOW 0
#define HIGH 300
#define STEP 20

int main ()
{
    int start;
    for (start = LOW; start <= HIGH; start += STEP)
        // (°F - 32) × 5/9
        printf("%3.0d F to %6.1f C\n", start, (start - 32) * (5.0/9.0));
    return 0;
}

// // Reverse order
// #define LOW 0.0
// #define HIGH 300.0
// #define STEP 20.0

// int main ()
// {
//     for (float start = HIGH; start >= LOW; start -= STEP)
//         // (°F - 32) × 5/9
//         printf("%3.0f F to %6.1f C\n", start, (start - 32) * (5.0/9.0));
//     return 0;
// }
