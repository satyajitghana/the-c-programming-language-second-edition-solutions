#include <stdio.h>
#include "buffer.h"

int getfloat(float *pn) {
    int c, sign = 0;

    /* skip the white spaces*/
    while (isspace(c = getch()))
        ;

    /* if its not a digit or a period */
    if (!isdigit(c) && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1: 1;
    if (c == '+' || c == '-') {
        c = getch();
    }
}
