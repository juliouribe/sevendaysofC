#include <stdio.h>
#include <ctype.h>

double atof(char[]);

int main()
{
    char num[] = "123.45e-5";
    printf("%6.9lf\n", atof(num));
    return 0;
}

/* atof:  convert string s to double */
double atof(char s[])
{
    double val, power;
    int i, sign;
    /* skip white space */
    for (i = 0; isspace(s[i]); i++)
        ;
    // Handle sign
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    // Handle left of decimal
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    // Decimal
    if (s[i] == '.')
        i++;
    // Right of decimal
    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    // Handle potential scientific notation.
    double doubleVal = sign * val / power;
    if (s[i] == 'e') {
        ++i;
        int eSign = s[i] == '+' ? 1 : -1;
        ++i;
        double ePower = 1.0;
        // To handle multi digit and replace s[i] on next line.
        for (int j = 1; j <= s[i] - '0'; ++j)
            ePower *= 10.0;
        if (eSign > 0)
            return doubleVal * ePower;
        else
            return doubleVal / ePower;
    }
    return doubleVal;
}

/*
"1235.6"

120000
1.2e+5

0.00012
1.2e-4
*/
