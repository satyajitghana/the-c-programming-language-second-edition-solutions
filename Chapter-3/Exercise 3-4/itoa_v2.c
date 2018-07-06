#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#define MAXLENGTH 100

void itoa(int number, char string[]);
void reverse(char str[]);

int main() {
    char buffer[MAXLENGTH];
    int num = INT_MIN;
    itoa(num, buffer);
    printf("%s\n", buffer);
    return 0;
}

void itoa(int n, char s[]) {
    int i, sign;
    sign = n;
    i = 0;
    do {
        s[i++] = abs(n % 10) + '0';
    } while (n /= 10);
    
    if (sign < 0) s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[]) {
    int c, i, j;
    for (i = 0, j = strlen(s)-1; i < j ; i++, j--) {
        c = s[j], s[j] = s[i], s[i] = c;
    }
}
