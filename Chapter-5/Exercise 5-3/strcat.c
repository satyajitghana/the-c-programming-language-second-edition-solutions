#include <stdio.h>

void strcat(char *, char *);

int main() {
    char s1[] = "satyajit ";
    char s2[] = "shadowleaf";
    strcat(s1, s2);
    printf("%s\n", s1);
    return 0;
}

void strcat(char *s, char *t) {
    while (*s != '\0') ++s;
    while ((*s = *t ) != '\0') {
        ++s;
        ++t;
    }
}
