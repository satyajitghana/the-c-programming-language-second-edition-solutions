#include <stdio.h>
#define MAXLINE 1000

int _getline(char line[], int maxline);
void _reverse(char orig[], char reversed[], int len);

int main() {
    int len;
    char line[MAXLINE], reverse[MAXLINE];
    while ((len = _getline(line, MAXLINE)) > 0) {
        _reverse(line, reverse, len);
        printf("%s", reverse);
    }
    return 0;
}

void _reverse(char orig[], char reversed[], int len) {
    int j = 0;
    int FLAG = 0;
    int start;
    // ignore the '\0'
    if (orig[len-1] == '\n') {
        start = len - 2;
        FLAG = 1;
    }
    else start = len-1;

    int i = 0;
    while (start >= 0 && (reversed[i] = orig[start--] )) ++i;
    if (FLAG == 1) reversed[i++] = '\n';
    reversed[i] = '\0';
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
