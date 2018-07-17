#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "buffer.h"

#define MAXWORD 1024

struct key {
    char *word;
    int count;
} keytab[] = {
    { "auto", 0 },
    { "break", 0 },
    { "case", 0 },
    { "char", 0 },
    { "const", 0 },
    { "continue", 0 },
    { "default", 0 },
    /* ... */
    { "unsigned", 0},
    { "void", 0 },
    { "volatile", 0 },
    { "while", 0 }
};

#define NKEYS ( sizeof keytab / sizeof keytab[0] )

int getword(char *, int);
int binsearch(char *, struct key *, int);
int rbinsearch(char *, struct key *, int, int);

/* count C keywords */
int main() {
    int n;
    char word[MAXWORD];
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            if ((n = rbinsearch(word, keytab, 0, NKEYS-1)) >= 0)
                keytab[n].count++;
    for (n = 0 ; n < NKEYS ; n++)
        if (keytab[n].count > 0)
            printf("%4d %s\n", keytab[n].count, keytab[n].word);
    return 0;
}

int getword(char *word, int lim) {
    int c, next;
    char *w = word;

    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c) && c != '_' && c != '#'
            && c != '\'' && c != '\"'
            && c != '/')
        return c;

    /* words with underscore or pound are treated as a single word */
    if (isalpha(c) || c == '_' || c == '#') {
        while (--lim) {
            next = getch(); 
            if (isalpha(next) || next == '_')
                *w++ = next;
            else {
                ungetch(next);
                break;
            }
        }
    } else if (c == '\'' || c == '\"') { /* if its a string treat the complete string as the word */
        while (--lim) {
            next = getch();
            if (next == c)
                break;
            else
                *w++ = next;
        }
    } else if (c == '/') { /* handling single line and multi line comments */
        next = getch();
        if (next == '*') {
            *w++ = next;
            while (--lim-1) {
                c = getch();
                if (c == '*') {
                    next = getch();
                    if (next == '/')
                        break;
                    else {
                        ungetch(next);
                    }
                } else
                    *w++ = c;
            }
        } else if (next == '/') {
            while (--lim-1) {
                c = getch();
                if (c == '\n')
                    break;
                *w++ = c;
            }
        } else {
            ungetch(next);
        }
    } /*else {
        return c;
    }*/
    *w = '\0';
    //printf(" # %s # ", word);
    //printf(" $ %d $", word[0]);
    return word[0];
}

/* binsearch: find word in tab[0] ... tab[n-1] */
int binsearch(char *word, struct key tab[], int n) {
    //if ()
    return -1;
}

/* rbinsearch: find word in tab[low] ... tab[high] */
int rbinsearch(char *word, struct key tab[], int low, int high) {
    int mid = (low + high) / 2;
    int res;
    if (low > high)
        return -1;
    if ((res = strcmp(word, tab[mid].word)) == 0)
        return mid;
    else if (res > 0 )
        rbinsearch(word, tab, mid+1, high);
    else
        rbinsearch(word, tab, low, mid-1);
}
