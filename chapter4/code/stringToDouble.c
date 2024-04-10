#include <stdio.h>
#include <ctype.h>

double atof(char []);
int atoi(double);

int main() {
    char myStr[] = "12.5";
    double num = atof(myStr);
    printf("%3.2lf\n", num);
    int other = atoi(num);
    printf("%d\n", other);
    return 0;
}

double atof(char s[])
{
    double val, power;
    int i, sign;

    for (i = 0; isspace(s[i]); i++) /* skip white space */
        ;

    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    // classic left to right str to int logic. Stops when not a digit.
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    // Skip the potential decimal place.
    if (s[i] == '.')
        i++;
    // Multiply val by 10's but also power. This lets you add to the right but
    // we'll divide by power at the end.
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    return sign * val / power;
}

int atoi(double num) {
    return (int) num;
}
