#include <stdio.h>

int getch();
void ungetch();

int main() {
    char c;
    ungetch('s');
    /* should cause an error */
    ungetch('a');
    /* should display s */
    putchar(getch());
    /* should display the entered character */
    putchar(getch());

    return 0;
}
