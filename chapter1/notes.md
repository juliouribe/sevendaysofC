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

```
int a, b, c;
a = b = c = 0;
```

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
a specific numeric value. When running the compiled program, control D provides
EOF while control C terminates immediately.

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

### 1.5.2 Character Counting

```
#include <stdio.h>
/* count characters in input; 1st version */
main()
{
    long nc;
    nc = 0;
    while (getchar() != EOF)
        ++nc;
    printf(%ld\n", nc);
}
```
To increment by one, we use `++nc`. Both `++nc` and `nc++` increment nc.
`--` will decrement in the same way.
int are 16 bits with a max value of 32767. long are 32 bits with a max of 2147483647
We can use a double instead and cover a massive large or small number. 10^308 on
some systems. The actual values depend on the system.

```
#include <stdio.h>
main()
{
    double nc;
    for (nc = 0; getchar() != EOF; ++nc)
        ;
    printf("%.0f\n", nc);
}
```
The body of the for loop is empty and replaced with a ;. Looks like for and while
loops needs brackets when its a multi line block and no brackets when its a single
line block.

### 1.5.3 Line Counting

```
#include <stdio.h>
main()
{
    int c, nl;
    nl = 0;
    while ((c = getchar()) != EOF)
        if (c == '\n')
            ++nl;
    printf("%d\n", nl);
}
```
We use double equals for comparison. Again single line blocks don't appear to
need brackets. Even though the if and code is multi lines, it looks like we can
kind of "chain" things and not need brackets.

A character written between single quotes, '\n', represents an integer value of
the character in the machine's character set. This is called a character constant.
'A' in ASCII is set to the value of 65. Escapes are also in ASCII. '\n' is set
to the value of 10 in ASCII.

### 1.5.4 Word Counting

```
#include <stdio.h>

#define IN 1    /* inside a word */
#define OUT 0   /* outside a word */
/* count lines, words, and characters in input */
main ()
{
    int c, nl, nw, nc, state;

    state = 0;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c = '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);
}
```
## 1.6 Arrays

Let's write a program that counts the occurrence of each digit, white space
(blank, tab, newline), and all other characters. There are 12 categories of
input so its convenient to use an array to hold the number of occurrences of
each digit rather than 10 variables.

```
#include <stdio.h>
main()
{
    inc c, i, nwhite, nother;
    int ndigit[10];

    nwhite = nother = 0;
    for (i = 0; i < 10; ++i)
        ndigit[i] = 0;

    while ((c = getchar()) != EOF)
        if (c >= '0' && c <= '9')
            // I think this subtracts current char from ASCII value char so you get the relative 0-9 instead of the actual ASCII.
            ++ndigit[c-'0'];
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else
            ++nother;

    printf("digits =");
    for (i = 0; i < 10; ++i)
        printf(" %d", ndigit[i]);
    printf(", white space = %d, other = %d\n", nwhite, nother);
}
```

## 1.7 Functions
```
#include <stdio.h>
// This is called a function prototype.
int power(int m, int n); // can also be written as int power(int, int);
/* test power function */
main()
{
    int i;
    for (i = 0; i < 10; ++i)
        printf("%d %d %d\n", i, power(2, i), power(-3, i));
    return 0;
}
/* power: raise base to n-th power; n >=0 */
int power(int base, int n)
{
    int i, p;

    p = 1;
    for (i = 1; i <= n; ++i)
        p = p * base;
    return p;
}
```

You have the function prototype at the top with arg types. They have to agree
with the arg types of the function definition but the variable names can change
or be missing entirely from the function prototype.

## 1.8 Arguments - Call by Value

When you pass in arguments from other variables, you don't pass in the actual
variable but instead make a local copy. You can modify this value an the value
or variable from before is not modified.

```
/* power: raise base to the n-th power: n >= 0; version 2 */
int power(int base, int n)
{
    int p;
    for (p = 1; n > 0; --n)
        p = p * base;
    return p;
}
```
In this example, n is a value passed and gets modified. However the value that
was passed is not modified since we create a local copy of n.

It is possible to actually modify the value passed in but that would require
defining and using a pointer instead. That will be covered in chapter 5.

## 1.9 Character Arrays

Check out the code folder for a program called `longestLine.c` that reads line
by line and saves a line if it is larger than the largest line so far. It uses
two functions: getline and copy.

## 1.10 External Variables and Scope

Looks like local variables and scope function pretty similarly to python. You
define something in main and it is only accessible to main. You can pass it with
a function call but then create a temporary local copy, unless its a pointer.
The variables in a function disappear when the routine ends so they are called
automatic variables in that they are created and cleared automatically when the
routine ends.

You can create "external variables" which are like globals and can be used in
any function. They must be defined outside of functions. In functions that you
want to use the external variable, you must declare them at the top of the
function `extern int max`. There are exceptions if the external declaration is
in the source file (current file?). Thus the example below the `extern` bit is
unnecessary since its the same file. However if the function was in another file,
then you would want it.

```
int max;
...
main ()
{
    extern int max;
    ...
    max = 0;
    ...
        if (len > max) {
            max = len
            ...
        }
    ...
}
```

definition: refers to the place where the variables is created and assigned storage
declaration: refers to the places where the nature of the variable is stated but
no storage is allocated.

I guess declaration is just saying the variable exists but no assignment.
Definition would include the assignment I believe.


