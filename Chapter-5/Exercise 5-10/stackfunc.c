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

double gettop() {
    if (sp > 0)
        return val[sp-1];
    printf("error : stack empty\n");
    return 0.0;
}

void swaptop() {
    if (sp > 1) {
        double n1 = pop();
        double n2 = pop();
        push(n1);
        push(n2);
    }
    else
        printf("error : need atleast 2 elements\n");
}

void copytop() {
    if (sp > 0) {
        double tmp = pop();
        push(tmp);
        push(tmp);
    } else {
        printf("error : stack empty\n");
    }
}

void clear() {
    sp = 0;
}
