#include <stdio.h>
#define MAXLINE 1000
#define TABSTOP 5

int _getline(char line[], int maxline);

int main() {
    int len;
    char line[MAXLINE], longest[MAXLINE];
    int max = 0;
    while (_getline(line, MAXLINE) > 0) {
        int i = 0, m = 0, flag = 0;
        while (line[i] != '\0') {
            if (line[i] == '\t') {
                int tab = m%TABSTOP;
                for (int j = 0 ; j < (TABSTOP - tab) ; j++) {
                    putchar('_'); // for testing
                    //putchar(' ');
                    m++;
                    flag = 1;
                }
            }
            else putchar(line[i]);
            if (flag == 1) {m--; flag = 0;}
            //if (flag != 1) {m++;flag = 0;}
            i++;m++;
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
