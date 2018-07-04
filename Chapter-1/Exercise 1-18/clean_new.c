#include <stdio.h>
#define MAXLINE 1000

int _getline(char line[], int maxline);
void copy(char to[], char from[]);
int clean(char line[], char cleaned[], int maxline);

int main() {
    int len;
    char line[MAXLINE], cleaned[MAXLINE];
    while (_getline(line, MAXLINE) > 0) {
        // this removes the blank lines even after cleaning
        if (clean(line, cleaned, MAXLINE) > 1) printf("%s", cleaned);
    }
    return 0;
}

int clean(char s[], char new[], int lim) {
    int i, j, c;
    i = j = 0;
    int FLAG = 0;
    while ((c = s[i++]) != '\0') {
        // removes the trailing tabs and spaces with a single space
        if (c == ' ' || c == '\t') FLAG = 1;
        else if (FLAG == 1) {
            new[j++] = ' ';
            new[j++] = c;
            FLAG = 0;
        }
        else new[j++] = c;
    }
    new[j] = '\0';
    return j;
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
