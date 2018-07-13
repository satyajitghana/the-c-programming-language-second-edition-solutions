#define ALLOCSIZE 10000 /* size of available space */

static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf;  /* next free position */

char *alloc(int n) /* return pointer to n characters */{
    /* end of the allocbuf - allocp should be >= n for it to fit */
    if (allocbuf + ALLOCSIZE - allocp >= n) { /* it fits */
        allocp += n;
        return allocp-n; /* old pointer */
    } else
        return 0;
}

void afree(char *p) /* free storage pointed to by p */ {
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}
