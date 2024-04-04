# Chapter 2 - Types, Operators, and Expressions

## 2.1 Variable Names

Variable names must start with a letter. Avoid variable names starting with an
underscore. Case sensitive. Typically shorter names for local variables and
longer names for external variables.

## 2.2 Data Types and Sizes

Basic data types:

    char a single byte, capable of holding one character in the local character set
    int an integer, typically reflecting the natural size of integers on the host machine
    float single-precision floating point
    double double-precision floating point

Short and long can be applied to integers.

    short int sh;
    long int counter;

Signed and unsigned can be applied to a char or integer. Unsigned means a char
ranges from 0 to 255. Signed means it ranges from -128 to 127.

The headers <limits.h> and <float.h> contain symbolic constants for these sizes.

## Constants

Constants end with an l L for long integers. Unsigned constants end with a u or U.
Floating point constants end in f or F. l or L to indicate a long double.

Leading 0 means octal. Leading 0X means hexadecimal.

Escape sequences:

    \a alert (bell) character \\
    \b backspace \?
    \f formfeed \'
    \n newline \"
    \r carriage return \ooo
    \t horizontal tab \xhh
    \v vertical tab
    \0 null character
    backslash
    question mark
    single quote
    double quote
    octal number
    hexadecimal number

'x' is a character constant and evaluates to some ASCII related value.
"I am a string" is a string constant or string literal, 0 or more characters.
You can split a string literal into multiple lines without operators.

    "this lines"
    "continues here"

String constants are an array of characters and can be any size. You can use
`strlen(s)` to get the length of a string.

```
/* strlen:  return length of s */
   int strlen(char s[])
   {
}
int i;
while (s[i] != '\0')
    ++i;
return i;
```

'x' is not equal to "x". "x" has an implied '\0' at the end of it.

Enumeration constant. An enum is a list of integer values as in. Names default to
ascending values starting at 0. Otherwise you can explicitly define them. Good
alt to using #define.

```
enum boolean { NO, YES };
enum escapes {
    BELL = '\a', BACKSPACE = '\b', TAB = '\t',
    NEWLINE = '\n', VTAB = '\v', RETURN = '\r'
};
/* FEB = 2, MAR = 3, etc. */
enum months {
    JAN = 1, FEB, MAR, APR, MAY, JUN,
    JUL, AUG, SEP, OCT, NOV, DEC
};
```

## 2.4 Declarations

You can declare and initialize on the same line or keep it separate.
```
int lower, upper, step;
char c, line[100];
int high = 100;
```

Constants
```
const double e = 2.71828182845905;
const char msg[] = "warning: ";
```


The const declaration can also be used with array arguments, to indicate that the function does not change that array:
`int strlen(const char[]);`

## 2.5 Arithmetic Operators

`/` truncates integers.

## 2.6 Relational and Logical Operators

Relational operators have lower precedence than arithmetic operations.
`i < lim-1` is taken as `i < (lim-1)`

&& and || are evaluated left to right. Evaluation stops as soon as the true or
falsehood is known.

By definition, the numeric value of a relational or logical expression is 1 if
the relation is true, and 0 if the relation is false. The unary negation
operator ! converts a non-zero operand into 0, and a zero operand in 1. A common
use of ! is in constructions like `if (!valid)`.

## 2.7 Type Conversions

You can add floats and integers. The int is converted into a float. There are no
automatic conversions that would lose information, only add.

```
/* atoi:  convert s to integer */
int atoi(char s[]) {
int i, n;
n = 0;
for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
    /* The 10 * n is for the left to right nature of piecing together hundreds place, tens, etc. */
    n = 10 * n + (s[i] - '0');
return n;
}

/* lower:  convert c to lower case; ASCII only */
int lower(int c) {
if (c >= 'A' && c <= 'Z')
    return c + 'a' - 'A';
else
    return c;
}
```

<ctype.h> has useful functions for lower casing and check if digits.
`lower()` and `isdigit(c)`.
<math.h> provides math functions. Uses double precision which is higher memory
than simple float. The sqrt function expects a double so if you use an integer
you must cast it as a double. `sqrt((double) n)`. The function prototype would
be `double sqrt(double)`.

## 2.8 Increment and Decrement Operators




