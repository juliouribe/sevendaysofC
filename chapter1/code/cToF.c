#include <stdio.h>

/* print Fahrenheit-Clesius table
    for fahr = 0, 20, ..., 300;
*/
int main() {
    float lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    float celsius;
    float fahr = lower; /* declaration and assignment in one line */
    
    while (fahr <= upper) {
        celsius = (5.0/9.0) * (fahr-32.0);
        // In 3.0f, the 3 stands for 3 wide and the 0 after the decimal place
        // instead of %d we use %f for floats? 6.1f allows one value after the decimal place.
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}
