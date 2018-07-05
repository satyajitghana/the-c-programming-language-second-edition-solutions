#include <stdio.h>
#define MAXLINE 1000

int _getline(char line[], int maxline);
int any(char string1[], char string2[]);

int main() {
    // take two lines as input
    int len1, len2;
    char line1[MAXLINE], line2[MAXLINE];
    while ((len1 = _getline(line1, MAXLINE)) > 0 && (len2 = _getline(line2, MAXLINE)) > 0) {
        // we get the location of the first character in line1 that matches any of the character in line2
        int loc = any(line1, line2);
        if (loc != -1) printf("Location : %d\n", loc);
        else printf("character not found\n");
    }
    return 0;
}

int any(char s1[], char s2[]) {
    for (int i = 0 ; s1[i] != '\n' && s1[i] != '\0'; i++) {
        for (int j = 0 ; s2[j] != '\n' && s2[j] != '\0'; j++) {
            if (s1[i] == s2[j]) return i;
        }
    }
    return -1;
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
