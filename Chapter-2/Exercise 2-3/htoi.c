#include <stdio.h>
#include <ctype.h>
#define MAXLINE 1000

int _getline(char line[], int maxline);
int htoi(char hex[]);

int main() {
    int len;
    char line[MAXLINE]; 
    while ((len = _getline(line, MAXLINE)) > 0) {
        // the line should start with 0x or 0X for it to work
        if (len > 2 && line[0] == '0' && (line[1] == 'x' || line[1] == 'X')) {
            printf("%d\n", htoi(line));
        }
    }
    return 0;
}

int htoi(char hex[]) {
    char c;
    int i = 2, _int = 0, mul = 1;
    // to determine the end of the hexadecimal number
    while ((hex[i] >= '0' && hex[i] <= '9') || (hex[i] >= 'a' && hex[i] <= 'f') || (hex[i] >= 'A' && hex[i] <= 'F')) ++i;
    for (int m = i-1; m >= 2 ; m--) {
        // if its a number
        if (hex[m] >= '0' && hex[m] <= '9') {
            _int = _int + (hex[m]-'0') * mul;
        }
        else {
            c = tolower(hex[m]);
            _int = _int + ((c-'a') + 10) * mul;
        }
        // to get 16^0, 16^1, 16^2 and so on
        mul = mul << 4;
        //printf(" *%d* ", mul);
    }
    return _int;
}

int _getline(char s[], int lim) {
    int c, i;
    for (i = 0 ; i < lim-1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    if (c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}
