/* Author : Satyajit Ghana
 * File Name : rmcomment.c
 *
 * */

#include <stdio.h>
#define MAXLINE 1000

int _getline(char line[], int maxline);

int main() {
    int len;
    char line[MAXLINE];
    int FLAG = 0, FLAG2 = 0;
    int IN_STRING = 0, IN_MLCOMMENT = 0;
    while ((len = _getline(line, MAXLINE)) > 0) {
        for (int i = 0 ; i < len-1 ; i++) {
            if (line[i] == '"') {
                if (IN_STRING) IN_STRING = 0;
                else IN_STRING = 1;
            }
            if (!IN_STRING) {
                // if it was a double slash comment straight-away break
                if (line[i] == '/' && line[i+1] == '/') {i++; FLAG2 = 1; break;}
                // for multiline comment
                if (line[i] == '/' && line[i+1] == '*') {i++; IN_MLCOMMENT = 1;}
                if (IN_MLCOMMENT == 1) {
                    // while ending is not found keep glancing
                    while (i < len-1) {
                        if (line[i] == '*' && line[i+1] == '/') {FLAG2=1; i+=2; IN_MLCOMMENT = 0; break;}
                        i++;
                    }
                }
            }
            putchar(line[i]);
        }
        if (FLAG2!= 1)
        putchar('\n');
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
