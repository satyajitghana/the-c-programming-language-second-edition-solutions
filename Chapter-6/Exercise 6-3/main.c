#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "io.h"

#define MAXWORD 100

int getword(char *, int);

/* word frequency count */
int main(int argc, char **argv) {
    int c;
    char *name = *argv;
    struct tnode *root;
    char word[MAXWORD];
    int lnum = 1;
    root = NULL;
    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0]))
            root = addtree(root, word, itoa(lnum));
       
        if (word[0] == '\n')
            lnum++;
    }
    treeprint(root);
    return 0;
}
