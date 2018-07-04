#include <stdio.h>

main() {
    int c;
    while ((c = getchar()) != EOF) {
        if (c == '\t' || c == '\b' || c == '\\') printf("\\\\");
        else putchar(c);
    }
}
