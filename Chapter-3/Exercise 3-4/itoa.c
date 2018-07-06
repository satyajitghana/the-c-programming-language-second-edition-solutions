#include <stdio.h>
#include <string.h>
#include <limits.h>
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
    int i, sign = 1;
    unsigned num;
    if(n < 0) {num = -n; sign = -1;}
    i = 0;
    do {
        s[i++] = num % 10 + '0';
    } while ((num /= 10) > 0);
    
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
