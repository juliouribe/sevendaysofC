#include <stdio.h>
#include <string.h>

void strcopy(char *s, char *t);

int main() {
    int val[] = { 1, 2, 3};
    int x = 1;
    // int *a = &val;
    // int *b = &val;
    int *c = &x;
    printf("%d\n", *c);
    // a++;
    // printf("%d\n", *a);
    // printf("%d\n", *b);
}

void strcopy(char *s, char *t) {
    while ((*s++ = *t++) != '\0') ;
}

    // char pa[] = "hello";
    // char *pc = pa;
    // pc++;
    // pc[0] = 'j';
    // // char pa[] = {'h', 'e', 'l', 'l', 'o'' '\0' };
    // char *pd = "hello";
    // char pb[] = "olleh";
    // // char stringone[] = "hello";
    // // char stringtwo[strlen(stringone)];
    // // pa = &stringone;
    // // pb = &stringtwo;
    // strcopy(pa, pb);
    // printf("%s\n", pa);
    // printf("%c\n", *pc);
    // printf("%s\n", pd);
    // printf("%c\n", *pb);

    // pa // pointer
    // *pa // "hello"
