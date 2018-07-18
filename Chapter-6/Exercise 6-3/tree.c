#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "io.h"
#include "tree.h"

/* addtree: add a node with w, line n, at or below p */
struct tnode *addtree(struct tnode *p, char *w, int n) {
    int cond;

    if (p == NULL) {    /* a new word has arrived */
        p = talloc();
        p -> word = _strdup(w);
        p -> count = 1;
        p -> left = p -> right = NULL;
        p -> lsize = 0;
        p -> lnum [p -> lsize ++] = n;
    } else if ((cond = strcmp(w, p -> word)) == 0) {
        p -> count++; /* repeated word */
        if (lsearch(p -> lnum, n, p -> lsize) < 0)
            p -> lnum[p -> lsize ++] = n;
    }
    else if (cond < 0)
        p -> left = addtree(p -> left, w, n);
    else
        p -> right = addtree(p -> right, w, n);
    return p;
}

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p) {
    if (p != NULL) {
        treeprint(p -> left);
        printf("%4d %s\n", p -> count, p -> word);
        for (int i = 0 ; i < p -> lsize ; i++)
            printf("\t%4d\n", p -> lnum[i]);
        treeprint(p -> right);
    }
}

/* talloc: make a tnode */
struct tnode *talloc(void) {
    return (struct tnode *) malloc(sizeof(struct tnode));
}

/* lsearch: linear search for ele in arr[0] ... arr[size] */
int lsearch(int *arr, int ele, int size) {
    for (int i = 0 ; i < size ; i++)
        if (arr[i] == ele)
            return i;
    /* ele not found in arr */
    return -1;
}
