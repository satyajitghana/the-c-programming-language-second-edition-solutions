#include <stdio.h>
#include <string.h>
#include "my_io.h"

#define MAXLINES 5000  /* max #lines to be sorted */
#define MAXSTORE 10000 /* same as that of alloc */

char *lineptr[MAXLINES];
char linestore[MAXSTORE];

void _qsort(char *lineptr[], int left, int right);

/* sort input lines */
int main() {
    int nlines; /* number of input lines read */

    if ((nlines = _readlines(lineptr, MAXLINES, linestore)) >= 0) {
        _qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

/* qsort: sort v[left] . . . .v[right] in increasing order */
void _qsort(char *v[], int left, int right) {
    int i, last;
    void swap(char *v[], int i, int j);

    if (left >= right) /* do nothing if array contains fewer than two elements */
        return;
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1 ; i <= right ; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    _qsort(v, left, last-1);
    _qsort(v, last+1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j) {
    char *temp;

    temp = v[i], v[i] = v[j], v[j] = temp;
}
