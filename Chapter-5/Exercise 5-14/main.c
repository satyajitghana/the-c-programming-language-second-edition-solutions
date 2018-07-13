#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "my_io.h"
#include "alloc.h"

#define MAXLINES 5000
char *lineptr[MAXLINES];

void _qsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));

int numcmp(char *, char *);

int main(int argc, char **argv) {
    int numeric = 0;
    if (argc > 1 && strcmp(*++argv, "-n") == 0) 
        numeric = 1;

    int nlines;
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        _qsort((void **) lineptr, 0, nlines-1, (int (*)(void*, void*))(numeric ? numcmp : strcmp));
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("input too big to sort\n");
        return 1;
    }
    return 0;
}

/* qsort: sort v[left]...v[right] into increasing order */
void _qsort(void *v[], int left, int right, int (*comp)(void *, void *)) {
    int i, last;
    void swap(void *v[], int, int);

    if (left >= right) return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1 ; i <= right ; i++)
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    _qsort(v, left, last - 1, comp);
    _qsort(v, last + 1, right, comp);
}

/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2) {
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

void swap(void *v[], int i, int j) {
    void *temp;
    temp = v[i], v[i] = v[j], v[j] = temp;
}
