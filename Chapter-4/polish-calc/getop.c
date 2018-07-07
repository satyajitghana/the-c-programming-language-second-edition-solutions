#include <ctype.h>
#include <stdio.h>
#define NUMBER '0'

int getch(void);
void ungetch(int);

void l(char c) { /* a log like thing */
    printf(" *%c* ", c);
}

/* to get the next operator or operand */
int getop(char s[]) {
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    //printf(" #%s# ", s);
    if (!isdigit(c) && c != '.')
        return c; /* not a number */
    i = 0;
    /* collect the rest of the integer part */
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    /* collect the fracitonal part */
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF) {
        //printf(" +%c+ ", c);
        ungetch(c);
    }
    return NUMBER;
}
