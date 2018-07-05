#include <stdio.h>
#include <ctype.h>
#define MAXLINE 1000

int _getline(char line[], int maxline);
void lower(char line[]);

int main() {
    int len;
    char line[MAXLINE];
    while ((len = _getline(line, MAXLINE)) > 0) {
        lower(line);
        printf("%s", line);
    }
    return 0;
}

void lower(char line[]) {
    int i = 0;
    while (line[i] != '\0') {
        line[i] = (isalpha(line[i])) ? ((isupper(line[i])) ? (line[i]+32) : (line[i])) : (line[i]);
        i++;
    }
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
