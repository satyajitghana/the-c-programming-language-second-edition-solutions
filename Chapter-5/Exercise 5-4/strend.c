#include <stdio.h>
#include <string.h>

int strend(char *, char *);

int main() {
    char s1[] = "satyajit";
    char s2[] = "jit";
    printf("%d\n", strend(s1, s2));
    return 0;
}

/* to check if the string t occurs at the end of s */
int strend(char *s, char *t) {
    int i, j;
    for (i = strlen(s)-1, j = strlen(t)-1; i >= 0 , j >= 0; i--, j--) {
        //printf(" *%c|%c* #%d|%d#\n", *(s+i), *(t+j), i, j);
        if (*(s+i) != *(t+j)) return 0;
        if (j == 0) return 1;
    }
    return 0;
}
