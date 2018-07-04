#include <stdio.h>

main() {
    int c, FOUND = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') FOUND = 1;
        else if (FOUND == 1) {
            putchar(' ');
            putchar(c);
            FOUND = 0;
        }
        else putchar(c);
    }
}
