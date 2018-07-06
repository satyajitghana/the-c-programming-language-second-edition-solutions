#include <stdio.h>
#include <string.h>
#include <limits.h>
#define MAXLENGTH 1000

int itob(int num, char str[], int base);
void reverse(char string[]);

int main() {
    char encoded[MAXLENGTH];
    int num = INT_MAX;
    int base = 62;
    if (itob(num, encoded, base) != -1) printf("%s\n", encoded);
    return 0;
}

int itob(int n, char s[], int b) {
    static const char CHARS[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    if (b < 2 || b > 62) return -1;
    int i = 0;
    do {
        s[i++] = CHARS[n % b];
    } while (n /= b);
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[]) {
    int c, i, j;
    for (i = 0, j = strlen(s)-1; i < j ; i++, j--) {
        c = s[j], s[j] = s[i], s[i] = c;
    }
}
