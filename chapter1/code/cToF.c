#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

/* print Fahrenheit-Clesius table
    for fahr = 0, 20, ..., 300;
*/
int main() {
    float celsius;
    float fahr = LOWER; /* declaration and assignment in one line */

    printf("While Loop\n");
    printf("###########\n");

    // While Loop
    while (fahr <= UPPER) {
        celsius = (5.0/9.0) * (fahr-32.0);
        // In 3.0f, the 3 stands for 3 wide and the 0 after the decimal place
        // instead of %d we use %f for floats? 6.1f allows one value after the decimal place.
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + STEP;
    }

    printf("\nFor Loop\n");
    printf("###########\n");

    // For Loop
    for (int fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP) {
        printf("%3.0f %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
    }
}
