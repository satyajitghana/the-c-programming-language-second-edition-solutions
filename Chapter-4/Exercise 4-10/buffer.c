#include <stdio.h>
#include <string.h>
#define BUFSIZE 100

int buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* buffer pointer (not a real pointer) */

int getch(void) /* get a (possibly pushed back) character */ {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */ {
    if (bufp >= BUFSIZE)
        printf("ungetch : too many characters\n");
    else
        buf[bufp++] = c;
}

void ungets(char s[]) /* push string s back to input */ {
    int i = strlen(s);
    while (i > 0) ungetch(s[--i]);
}
