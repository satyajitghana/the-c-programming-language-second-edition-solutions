#include <stdio.h>
#include <string.h>
#include "alloc.h"
#define MAXLEN 1000 /* max length of any input line */

int _getline(char str[], int lim) {
    int c, i = 0;
    while (--lim && (c = getchar()) != EOF && c != '\n')
        str[i++] = c;
    if (c == '\n') str[i++] = c;
    str[i] = '\0';

    return i;
}

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines) {
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = _getline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len-1] = '\0'; /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

/* _readlines: doesn't use the alloc for memory allocation */
int _readlines(char *lineptr[], int maxlines, char *linestore) {
    int len, nlines;
    char line[MAXLEN];
    while ((len = _getline(line, MAXLEN)) > 0) {
        if (nlines >= maxlines)
            return -1;
        else {
            line[len-1] = '\0'; /* delete the newline */
            strcpy(linestore, line);
            lineptr[nlines++] = linestore;
        }
        linestore += len;
    }
    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines) {
    int i;

    for (i = 0 ; i < nlines ; i++)
        printf("%s\n", lineptr[i]);
}
