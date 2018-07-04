#include <stdio.h>

main() {
    int c;
    int blank, tabs, nl;
    blank = tabs = nl = 0;
    while ((c = getchar()) != EOF) {
        putchar(c);
        if (c == ' ') ++blank;
        else if (c == '\t') ++tabs;
        else if (c == '\n') ++nl;
    }
    printf("\nBlanks : %d, Tabs : %d, New Lines : %d\n", blank, tabs, nl);
}
