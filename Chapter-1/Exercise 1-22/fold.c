#include <stdio.h>
#define MAXLINE 1000
#define MAXLENGTH 50

int _getline(char line[], int maxline);

int main() {
    int len, counter = 0;;
    char line[MAXLINE];
    while ((len = _getline(line, MAXLINE)) > 0) {
        for (int i = 0 ; i < len ; i++) {
            if (counter > MAXLENGTH) {
                while (line[i] != ' ') {putchar(line[i]);i++;}
                putchar('\n'); i++;
                counter = 0;
            }
            putchar(line[i]);
            counter++;
        }
    }
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
