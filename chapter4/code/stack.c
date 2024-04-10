#include <stdio.h>
#define MAXVAL 100 /* maximum depth of val stack */

void push(double);
double pop(void);
void peek(void);
void duplicate(void);
void swap(void);
void show(void);

int idx = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */

int main(){
    push(1.0);
    push(2.0);
    push(3.0);
    show();

    peek();
    
    swap();
    show();

    duplicate();
    show();

    return 0;
}

/* push: push f onto value stack */
void push(double f)
{
    if (idx < MAXVAL)
        val[idx++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (idx > 0)
        return val[--idx];
    else
        printf("error: stack empty\n");
    return 0.0;
}

void peek(void){
    printf("%lf\n", val[idx-1]);
}

void duplicate(void){
    if (idx){
        double top = val[idx-1];
        push(top);
    } 
}

void swap(void){
    if (idx > 1){
        double top = val[idx-1];
        val[idx-1] = val[idx-2];
        val[idx-2] = top;
    }
}

void show(void){
    printf("[");
    for (int i = 0; i < idx; i++) {
        printf("%lf", val[i]);
        if (i < idx - 1)
            printf(", ");
        
    }
    printf("]\n");
}