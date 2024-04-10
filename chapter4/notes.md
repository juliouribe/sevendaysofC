# Chapter 4 - Functions and Program Structure

## 4.1 Basics of Functions
A program with several example functions to parse lines that contain 'ould'.

```
#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int getline(char line[], int max)
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";   /* pattern to search for */

/* find all lines matching pattern */
main() {
    char line[MAXLINE];
    int found = 0;
    while (getline(line, MAXLINE) > 0)
        if (strindex(line, pattern) >= 0) {
            printf("%s", line);
            found++;
        }
    return found;
}

/* getline:  get line into s, return length */
int getline(char s[], int lim) {
    int c, i;

    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

/* strindex:  return index of t in s, -1 if none */
int strindex(char s[], char t[]) {
    int i, j, k;
    for (i = 0; s[i] != '\0'; i++) {
        for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
    return i;
    }
    return -1;
}
```

## 4.2 Functions Returning Non-integers

Take a string s and return a double.
```
#include <ctype.h>

/* atof:  convert string s to double */

double atof(char s[]) {
    double val, power;
    int i, sign;

    for (i = 0; isspace(s[i]); i++)  /* skip white space */
        ;

    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;

    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');

    if (s[i] == '.')
        i++;

    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    return sign * val / power;
}
```

Example function for computing polish notation using a stack.

```
#include <stdio.h>
   #include <stdlib.h>  /* for  atof() */
   #define MAXOP   100  /* max size of operand or operator */
   #define NUMBER  '0'  /* signal that a number was found */
   int getop(char []);
   void push(double);
   double pop(void);
   /* reverse Polish calculator */
   main()
   {
}
int type;
double op2;
char s[MAXOP];
while ((type = getop(s)) != EOF) {
    switch (type) {
    case NUMBER:
        push(atof(s));
        break;
    case '+':
        push(pop() + pop());
        break;
    case '*':
        push(pop() * pop());
        break;
    case '-':
        op2 = pop();
        push(pop() - op2);
        break;
    case '/':
        op2 = pop();
        if (op2 != 0.0)
            push(pop() / op2);
        else
            printf("error: zero divisor\n");
        break;
    case '\n':
        printf("\t%.8g\n", pop());
        break;
    default:
        printf("error: unknown command %s\n", s);
        break;
}
}
return 0;
external variables for push and pop
   void push( double f) { ... }
   double pop(void) { ... }

    int getop(char s[]) { ... }
routines called by getop
```

## 4.3 External Variables
Some discussion of when to use external variables for functions sharing access
to the same data.

## 4.4 Scope Rules

Automatic variables (arg variables within a function) are local and only available
inside of the function defined.

Variables can be declared at the top of a file and are available almost globally
to every function or code below it.

For external variables, they can be referenced in a file while defined elsewhere
and can be references before declaring as long as you declare it in another file.
You must refer to the external variable before using it.

In one file you may have `int sp;`. Then in another file you can refer to this
using `extern int sp;`. These are just declarations. Also, you don't need to
include array sizes in the external reference. It will be in the initial declaration
like file 2 in the example below.

file 1, `extern double val[];`
file 2, `double val[MAXVAL];`

## 4.5 Header Files

Place common materials, such as util functions or other useful pieces of code,
into a header file, such as `calc.h`.

calc.h
```
#define NUMBER '0'
void push(double);
double pop(void);
int getOp(char []);
int getCh(void);
void unGetCh(int);
```

main.c
```
#include <stdio.h>
#include <stdlib.h>
#include "calc.h"
#define MAXOP 100
main() {
    ...
}
```

getOp.c
```
#include <stdio.h>
#include <ctype.h>
#include "calc.h"
getOp() {
    ...
}
```

With this structure, main.c is what you will most likely run. The header file is
there to aggregate the different modules. Looks like function prototypes go in
there. Then the modules themselves, getOp.c, import the header to read the function
prototype and actually define the function.

It's not quite clear in what order things are read. Seems like the modules reference
the header parent file but the parent doesn't reference the children other than
the prototype definitions. If at compile time, the whole directory is read then
this makes sense as the compiler will know to look for those functions and tie
it all together.

## 4.6 Static Variables

Use static variables to make them private to the file they are located in. They
will not be available for other files to use as external variables. They also
are permanent variables so you can continue to reference them as they always have
a place in storage.

`static char buf[BUFFSIZE];`

## 4.7 Register Variables

Register variables are there to tell a machine that this will be used often. Like cache?

`register int x;`

THis can only be applied to automatic variables.

```
f(register unsigned m, register long n) {
    register int;
    ...
}
```

## 4.8 Block Structure

Conditional vars are defined newly each time and accessible within block scope.

Using the same name for an automatic variable can override/ignore previously
defined variables. In this example, int x and y are ignored and newly defined
as double x and y.

```
int x;
int y;

f(double x) {
    double y;
    ...
}
```

## 4.9 Initialization

In absence of initialization, external and static variables are initialized to zero.
Automatic and register variables have undefined (garbage) initial values.

To use external and static variables, you must initialize with a constant expression.
For auto and register variables, its not limited to being a constant.

Creating an array with values. Size can be omitted since the compiler will count
the number of values in the initialization.
`int days[] = { 31, 28, 31, 30, 31, 30 }`

`char pattern = "ould";` and `char pattern[] = { 'o', 'u', 'l', 'd', '\0' };` are equal.

## 4.10 Recursion

You can use functions recursively. Nothing fancy needed. See code example for
quicksort.

## 4.11 The C Preprocessor

There is a separate first step in compilation. The two most common are #include
and #define.

When you do file inclusion, that line is replaced by the contents of the linked
file. If the file name was in quotes "", then it looks in the same folder as the
source file. If its in carrots <>, it follows and implementation defined rule to
find the file.

You can use macros with #define to define function like stuff that kind of takes
in variables.

```
#define  max(A, B)  ((A) > (B) ? (A) : (B))

x = max(p+q, r+s);

// Results into this
x = ((p+q) > (r+s) ? (p+q) : (r+s));
```

You can undefine macros to make sure your function is read.

```
#undef gethchar
int getchar(void) { ... }
```

Some cool stuff with using #if for precompilation code inclusion or omission.

This makes sure that the contents of hdr.h are only included once.
```
#if !defined(HDR)
   #define HDR
   /* contents of hdr.h go here */
#endif
```
