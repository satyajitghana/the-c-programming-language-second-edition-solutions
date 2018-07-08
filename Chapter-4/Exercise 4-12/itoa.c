#include <stdio.h>

void itoa(int i, char s[]) {
    static int index = 0;
    static int sign = -1;
    if (i/10)
        itoa(i/10, s);
    //printf(" *%d#%d*", i%10);
    if (sign < 0 && i < 0) {
        s[index++] = '-';
        sign = 0;
    }
    s[index++] = abs(i%10) + '0';
    s[index] = '\0';
}
