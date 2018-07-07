#include <stdio.h>

int getch();
void ungetch();
void ungets(char []);

int main() {
    char c, s[] = "satyajit\n";
    /* should push s back to the buffer, from tail to head, since buffer is a stack */
    ungets(s);
    /* should print my first name and then keeps reading the input until EOF */
    while ((c = getch()) != EOF) putchar(c);
    return 0;
}
