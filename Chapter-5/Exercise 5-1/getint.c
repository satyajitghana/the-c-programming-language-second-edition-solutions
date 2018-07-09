#include <ctype.h>
#include <stdio.h>

int getch(void);
void ungetch(int);

/* get an integer from input into *pn */

int getint(int *pn) {
    int c, sign = 0;
    while (isspace(c = getch()))
        ;
    /* if its not a digit */
    if (!isdigit(c) && c != EOF && c != '+' && c!= '-') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    
    /* if '+' or '-' is not followed by a digit then push it back to input*/
    if (!isdigit(c)) {
        ungetch(c);
        /* if the sign was read */
        if (sign != 0) ungetch((sign == -1) ? '-': '+');
        return 0;
    }

    for (*pn = 0 ; isdigit(c) ; c = getch())
        *pn = 10 * *pn + (c - '0');
    
    *pn *= sign;
    
    if (c != EOF)
        ungetch(c);
    return c;
}
