# Chapter 6 - Structures

## 6.1 Basics of Structure


```
struct point {
    int x;
    int y;
}

struct maxpt = { 320, 200 };
maxpt.x or maxpt.y
```

Structs can be nested

```
struct rect {
    struct point pt1;
    struct point pt2;
}
screen.pt1.x
```

## 6.2

*p.x will break because . goes faster.
(*p).x is the way to write it.
p->x will work as well.

struct {
    int len;
    char *str;
} *p;

++p->str will increment the value of str, the pointer inside the struct.

## 6.3


