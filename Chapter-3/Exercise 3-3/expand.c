#include <stdio.h>
#include <ctype.h>
#define MAXLINE 1000

int _getline(char line[], int maxline);
void expand(char to_expand[], char expanded[]);

int main() {
    int len;
    char line[MAXLINE], expanded[MAXLINE];
    int max = 0;
    while ((len = _getline(line, MAXLINE)) > 0) {
        expand(line, expanded);
        printf("%s", expanded);
    }
    return 0;
}

void expand(char s1[], char s2[]) {
    int i, j;
    i = j = 0;
    while (s1[i] != '\0') {
        char c = s1[i];
        // if there's a dash after a alpha-numeric character, then start expanding
        if (isalnum(s1[i]) && s1[i+1] == '-' && s1[i+2] > s1[i]) {
            //printf(" valid ");
            while (c < s1[i+2]) {
                s2[j++] = c;
                c++;
            }
            // to skip the dash
            i++;
        }
        else
            s2[j++] = s1[i];
        i++;
    }
    s2[j] = '\0';
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
