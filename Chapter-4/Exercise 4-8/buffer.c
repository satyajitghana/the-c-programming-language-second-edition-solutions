#include <stdio.h>
#include <string.h>
#define BUFSIZE 100

/* assuming there's going to be only one char pushback */

char buf; /* buffer for ungetch */
int bufp = -1; /* buffer pointer (not a real pointer) */
/* -1 -> empty 0 -> one pushed char */

int getch(void) /* get a (possibly pushed back) character */ {
    if (bufp == 0) {
        bufp = -1;
        return buf;
    }
    else
        return getchar();
}

void ungetch(int c) /* push character back on input */ {
    if (bufp == 0) {
        printf("ungetch : too many characters\n");
    }
    else {
        buf = c;
        bufp = 0;
    }
}
