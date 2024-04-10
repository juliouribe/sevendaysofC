# Chapter 5 - Pointers and Arrays

A pointer is a variable that contains the address of a variable. Pointers and
arrays can be similar. 'void *(pointer to void)` is used as a generic pointer.

## 5.1 Pointers and Addresses

`p = &c;` sets p equal to the address of c. The & operator only applies to
objects in memory: variables and array elements. It cannot be applied to expressions,
constants, or register variables.

The unary operator * is the indirection or dereferencing operator. When applied
to a pointer, * accesses the object the pointer points to.

```
int x = 1, y = 2, z[10];
int *ip;                    /* ip is a pointer to int */
ip = &x;                    /* ip now points to x */
y = *ip;                    /* y is now 1 */
*ip = 0;                    /* x is now 0 */
ip = &z[0];                 /* ip now points to z[0] */
```

## 5.2 Pointers and Function Arguments

Since you can't actually modify values by using functions, you can use pointers
to actually make changes.

```
void swap(int *px, int *py)  /* interchange *px and *py */
{
    int temp;
    temp = *px;
    *px = *py;
    *py = temp;
}

// Loop that fills an array with integers
int n, array[SIZE], getint(int *);
for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
    ;
```

## 5.3 Pointers and Arrays


