#include <stdio.h>

int getch();
void ungetch();
void ungets(char []);

int main() {
    char c, s[] = "satyajit\n";
    ungets(s);
    while ((c = getch()) != EOF) putchar(c);
    return 0;
}
