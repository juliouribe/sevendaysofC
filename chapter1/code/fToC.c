#include <stdio.h>

#define LOW 0.0
#define HIGH 300.0
#define STEP 20.0

float fToC(float);

int main ()
{
    float start;
    float c; 
    for (start = LOW; start <= HIGH; start += STEP) {
        // (°F - 32) × 5/9
        c = fToC(start);
        printf("%3.0f F to %6.1f C\n", start, c);
    }
    return 0;
}

float fToC (float f)
{
    return ((f - 32.0) * (5.0/9.0));
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
