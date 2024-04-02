# Chapter 1: A Tutorial Introduction

## 1.1 Getting Started

To compile a program,
`cc hello.c`

Produces a file called `a.out`. Run that file by running `./a.out`

## 1.2 Variables and Arithmetic Expressions

Looks like you might define the variable and assign separately.

Primitive types in C
int     numbers w/o decimal
float   numbers with decimal
char    single byte char
short   short integer
long    long integer
double  double precision floating point

While loop functions pretty much the same as Python and JS. Only runs when the
expression is true.

while (expression) {
    // code
}

In C, integer division truncates: any fractional part is discarded. To divide by
5/9ths, you would multiple by 5 first and then divide the total by 9. If you
multiplied by 5/9 you might get 0. 5/9 might resolve to 0. Takeaway, multiply
first and then divide or use a float.

%d      print as decimal integer
%6d     print as decimal integer, at least 6 characters wide
%f      print as float
%6f     print as float, at least 6 characters wide
%.2f    print as float, 2 characters after the decimal point
%6.2f   print as float, 6 wide and at least 2 after the decimal point

## 1.3 The `for` Statement

The for loop looks pretty similar but note the incrementing portion and lack of
braces. You also need to declare the variable outside of the for loop statement.
```
int main()
{
    int fahr;
    for (fahr = 0; fahr <= 300; fahr = fahr + 20)
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}
```

## 1.4 Symbolic Constants

Use symbolic constants to help provide more context and meaning to "magic" numbers
in your code so other programmers understand your code better.

Symbolic constants are kind of like globals but they simply replace text where
the symbolic name is used. It's not quite a variable per say since you don't
actually declare it but it replaces the text and makes it interchangeable.

```
#define LOWER 0     /* lower limit of the table */
#define UPPER 300   /* upper limit */
#define STEP 20     /* step size */

int main()
{
    int fahr;
    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}
```

## 1.5 Character Input and Output

Text streams are used to dealt with input and output. A text stream is a sequence
of characters divided into lines; each line consists of zero or more characters
followed by a newline character.

Reads the next input character from a text stream and returns that as its value.
c = getchar();

Print a character. Similar to printf but for single characters.
putchar(c);

### 1.5.1 File Copying

Here's an example of reading character by character and printing it out.
```
#include <stdio.h>
/* copy input to output; 1st version */
main ()
{
    int c;

    c = getchar();
    while (c != EOF) {
        putchar(c);
        c = getchar();
    }
}
```

getchar() returns a distinctive value when there is no more input. This value is
called EOF, end of file, and we can exit the loop once we get that. We make c an
int variable because it needs to be large enough to hold EOF. If we simply used
char as the type, it would not be large enough to store EOF.

EOF is an integer defined in <stdio.h>. It's a symbolic constant that refers to
a specific numeric value.

Seems like `c = getchar()` returns a value so we can make the code above more concise.

```
#include <stdio.h>
/* copy input to output; 2nd version */
main()
{
    int c;

    while ((c getchar()) != EOF)
        putchar(c);
}
```
Be careful when comparing like this. != has high priority so you need the
parentheses or it will evaluate immediately.

