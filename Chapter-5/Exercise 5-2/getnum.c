#include <ctype.h>
#include <stdio.h>
#include "buffer.h"

/* get an integer from input into *pn */

int getint(int *pn) {
    int c, sign, rsign = -1;
    while (isspace(c = getch()))
        ;
    /* if its not a digit */
    if (!isdigit(c) && c != EOF && c != '+' && c!= '-') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        rsign = 0;
        c = getch();
    }
    
    /* if '+' or '-' is not followed by a digit then push it back to input*/
    if (!isdigit(c)) {
        ungetch(c);
        /* if the sign was read */
        if (rsign != -1) ungetch((sign == -1) ? '-': '+');
        return 0;
    }

    for (*pn = 0 ; isdigit(c) ; c = getch())
        *pn = 10 * *pn + (c - '0');
    
    *pn *= sign;
    
    if (c != EOF)
        ungetch(c);
    return c;
}

int getfloat(float *pn) {
    int c, sign, power = 1;
    int store = -1;

    /* skip the white spaces*/
    while (isspace(c = getch()))
        ;

    /* if it's not a digit */
    if (!isdigit(c)
            && c != EOF
            && c != '+'
            && c != '-'
            && c != '.') {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1: 1;
    if (c == '+' || c == '-' || c == '.') {
        store = c;
        c = getch();
    }

    /* if '+' or '-' or '.' is not followed by a digit then push it back to input */
    if (!isdigit(c)) {
        ungetch(c);
        /* if +, - or . was read */
        if (store != -1) ungetch(store);
        return 0;
    }

    /* get the integer part */
    for (*pn = 0.0 ; isdigit(c) ; c = getch())
        *pn = *pn * 10.0 + (c - '0');
    /* get the fractional part */
    if (c == '.')
        while (isdigit(c = getch())) {
            *pn = *pn * 10 + (c - '0');
            power *= 10;
        }

    *pn = sign * *pn / power;

    if (c != EOF) ungetch(c);

    return c;
}
