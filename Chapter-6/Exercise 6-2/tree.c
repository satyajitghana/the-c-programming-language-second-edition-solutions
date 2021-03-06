#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "io.h"
#include "tree.h"

/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w, int n) {
    int cond;

    if (p == NULL) {    /* a new word has arrived */
        p = talloc();
        p -> word = _strndup(w, n);
        p -> count = 1;
        p -> left = p -> right = NULL;
    } else if ((cond = strncmp(w, p -> word, n)) == 0)
        p -> count++; /* repeated word */
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
        treeprint(p -> right);
    }
}

/* talloc: make a tnode */
struct tnode *talloc(void) {
    return (struct tnode *) malloc(sizeof(struct tnode));
}
