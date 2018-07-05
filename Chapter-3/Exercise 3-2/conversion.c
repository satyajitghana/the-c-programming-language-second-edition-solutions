#include <stdio.h>
#define MAXLINE 1000

int _getline(char line[], int maxline);
void escape(char formatted[], char orig[]);
void revert(char formatted[], char orig[]);

int main() {
    int len;
    char line[MAXLINE], new[MAXLINE], _new[MAXLINE];
    while ((len = _getline(line, MAXLINE)) > 0) {
        escape(new, line);
        printf("formatted : %s\n", new);
        revert(_new, line);
        printf("reverted : %s", _new);
    }
    return 0;
}

void escape(char f[], char s[]) {
    int i, j;
    for (i = j = 0 ; s[i] != '\0' ; i++) {
        switch(s[i]) {
            case '\n' : {f[j++] = '\\'; f[j++] = 'n'; break;}
            case '\t' : {f[j++] = '\\'; f[j++] = 't'; break;}
            default : f[j++] = s[i];
        }
    }
    f[j] = '\0';
}

void revert(char f[], char s[]) {
    int i, j;
    for (i = j = 0 ; s[i] != '\0' ; i++) {
        if (s[i] == '\\')
            switch(s[++i]) {
                case 'n' : {f[j++] = '\n'; break;}
                case 't' : {f[j++] = '\t'; break;}
                default : {f[j++] = s[i-1]; f[j++] = s[i];}
            }
        else f[j++] = s[i];
    }
    f[j] = '\0';
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
