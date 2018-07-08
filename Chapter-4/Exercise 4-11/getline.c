#include <stdio.h>

int _getline(char str[], int lim) {
    int c, i = 0;
    while (--lim && (c = getchar()) != EOF && c != '\n')
        str[i++] = c;
    if (c == '\n') str[i++] = c;
    str[i] = '\0';

    return i;
}
