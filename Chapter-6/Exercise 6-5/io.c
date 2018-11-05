#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "buffer.h"
#include "io.h"

char *_strdup(char *s) { /* make a duplicate of s */
    char *p;

    p = (char *) malloc(strlen(s) + 1); /* +1 for '\0' */
    if (p != NULL)
        strcpy(p, s);
    return p;
}

/* _strndup: make a duplicate of at most 6 characters of s*/
char *_strndup(char *s, int n) {
    char *p;

    p = (char *) malloc(n +1);
    if (p != NULL)
        strncpy(p, s, n);
    return p;
}

/* getword: get next word or character from input */
int getword(char *word, int lim) {
    int c;
    char *w = word;

    /* skip the whitespaces */
    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }

    while (--lim) {
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
        w++;
    }
    *w = '\0';
    return word[0];
}
