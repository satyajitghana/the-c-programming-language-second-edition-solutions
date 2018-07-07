#include <stdio.h>
#define MAXVAL 100 /* maximum depth of the val stack */

int sp = 0; /* next free stack position */
double val[MAXVAL];

void push(double f) {
    //putchar('p');
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error : stack full, can't push %g\n", f);
}

double pop() {
    if (sp > 0)
        return val[--sp];
    else {
        printf("error : stack empty\n");
        return 0.0;
    }
}
