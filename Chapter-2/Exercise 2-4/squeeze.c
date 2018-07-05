#include <stdio.h>
#define MAXLINE 1000

int _getline(char line[], int maxline);
void squeeze(char string1[], char string2[]);

int main() {
    // take two lines as input
    int len1, len2;
    char line1[MAXLINE], line2[MAXLINE];
    while ((len1 = _getline(line1, MAXLINE)) > 0 && (len2 = _getline(line2, MAXLINE)) > 0) {
        squeeze(line1, line2);
        printf("%s", line1);
    }
    return 0;
}

// deletes every character in s1 that matches any of the character in s2
void squeeze(char s1[], char s2[]) {
    int i, j;
    for (i = j = 0 ; s1[i] != '\n' && s1[i] != '\0' ; i++) {
        int FOUND = 0;
        for (int k = 0 ; s2[k] != '\n' && s2[k] != '\0' ; k++) {
            if (s1[i] == s2[k]) {FOUND = 1; break;}
        }
        if (!FOUND) s1[j++] = s1[i];
    }
    s1[j++] = '\n';
    s1[j] = '\0';
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
