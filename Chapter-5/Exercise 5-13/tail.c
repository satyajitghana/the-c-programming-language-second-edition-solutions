#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLENGTH 10240
#define MAXLINES 1024

char *linestore[MAXLINES];
char line[MAXLENGTH];

int main(int argc, char **argv) {
    char *name = *argv;
    int nlines = 10;
    int lc = 0; /* line count */
    int c;
    while (--argc > 0 && **++argv == '-') {
        while (c = *++(*argv))
            switch(c) {
                case 'n':
                    //printf("%s\n", *argv);
                    //printf("%d\n", nlines);
                    break;
                default:
                    printf("%s: illegal character %c\n", name, **argv);
                    argc = 0;
                    break;
            }
    }
    if (argc != 1) {
        printf("Usage : %s -n <number of lines>\n", name);
        return 0;
    } else {
        nlines = atoi(*argv);
        if (nlines > 0)
            ;
            //printf("%d\n", nlines);
        else
            nlines = 10;

        size_t maxlen = MAXLENGTH;
        char *lineptr = line;

        /* getline takes the address of the address to the first character of the buffer,
         * and address of the maxlength for the buffer,
         * and the standard input file, stdin */
        while (getline(&lineptr, &maxlen, stdin)) {
            int len = strlen(lineptr);
            if (lineptr[len-1] == '\n') {
                lineptr[len-1] = '\0';
                --len;
            }
            if (len == 0) break;
            /* if there was a line */
            *(linestore + lc) = lineptr;
            lc++;
            //printf("string : *%s*\n", lineptr);
            lineptr += len+1;
            //printf("*%s*\n", line);
            //printf("length : %d\n", len);
        }
        printf("\nHere are the last %d lines : \n", nlines > lc ? lc: nlines);
        while (lc-- && nlines--) {
            printf("%s\n", *(linestore + lc));
        }
    }
    return 0;
}
