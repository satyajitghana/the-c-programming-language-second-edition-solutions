#include <stdio.h>

int getch();
void ungetch();

int main() {
    char c;
    /* this will directly push EOF to the buffer ungetch(EOF);*/
    /* should keep reading the input until EOF */
    while ((c = getch()) != EOF) putchar(c);
    return 0;
}
