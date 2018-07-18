#include <stdio.h>

void itoa(int a, char *s) {
    static int i = 0;
    if (a < 0) {
        s[i++] = '-';
        a *= -1;
    }
    if (a > 0) {
        itoa(a/10, s);
        s[i++] = '0' + a%10;
        //printf("%d %d\n", a, i++);
    }
}
