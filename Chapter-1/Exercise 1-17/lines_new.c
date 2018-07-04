#include <stdio.h>
#define MAXLENGTH 1000
#define MAXLINES 20
#define SIZELIM 80

int _getline(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
    int len, i = 0;
    char line[MAXLENGTH], lines[MAXLINES][MAXLENGTH];
    while ((len = _getline(line, MAXLENGTH)) > 0) {
        if (len > SIZELIM) {
            copy(lines[i++], line);
        }
    }
    for (int j = 0 ; j < i ; j++) printf("%s", lines[j]);
    return 0;
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

void copy(char to[], char from[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0') ++i;
}
