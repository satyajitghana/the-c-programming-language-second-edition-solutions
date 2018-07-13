#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "my_io.h"
#include "alloc.h"

#define MAXLINES 5000
char *lineptr[MAXLINES];

void _qsort(void *lineptr[], int left, int right, int (*comp)(void *, void *), int order);

int numcmp(char *, char *);
int strcmpi(char *, char *);

int main(int argc, char **argv) {
    int numeric = 0;
    //int reverse = -1;
    int order = 1;
    int ignore_case = 0;
    char *name = *argv;
    char c;
    /*if (argc > 1 && strcmp(*++argv, "-n") == 0) 
        numeric = 1;*/
    while (--argc > 0 && **++argv == '-') {
        while (c = *++(*argv))
                switch(c) {
                    case 'n':
                        numeric = 1;
                        break;
                    case 'r':
                        order *= -1;
                        break;
                    case 'f':
                        ignore_case = 1;
                        break;
                    default:
                        printf("%s: illegal character %c\n", name, c);
                        argc = -1;
                        break;
                    }
    }
    if (argc != 0) {
        printf("Usage: %s -n -r\n"
                "n: numeric sort\n"
                "r: reverse sort\n"
                "f : fold (ignore case)\n", name);
        return 0;
    }
    //return 0;
    int nlines;
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        _qsort((void **) lineptr, 0, nlines-1, (int (*)(void*, void*))(numeric ? numcmp : ((ignore_case) ? strcmpi : strcmp)), order);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("input too big to sort\n");
        return 1;
    }
    return 0;
}

/* qsort: sort v[left]...v[right] into increasing order */
void _qsort(void *v[], int left, int right, int (*comp)(void *, void *), int order) {
    int i, last;
    void swap(void *v[], int, int);

    if (left >= right) return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1 ; i <= right ; i++)
        if ((order)*(*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    _qsort(v, left, last - 1, comp, order);
    _qsort(v, last + 1, right, comp, order);
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

int strcmpi(char *s1, char *s2) {
    void strupr(char *);

    char v1[1024], v2[1024];
    strcpy(v1, s1);
    strupr(v1);
    strcpy(v2, s2);
    strupr(v2);

    return strcmp(v1, v2);
}

void strupr(char *s) {
    while(*s != '\0') {
        if (*s >= 'a' && *s <= 'z')
            *s = 'A' + (*s-'a');
        s++;
    }
}

void swap(void *v[], int i, int j) {
    void *temp;
    temp = v[i], v[i] = v[j], v[j] = temp;
}
