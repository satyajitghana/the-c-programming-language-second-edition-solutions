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
    int number = 6;
    char *np;
    int EXPECT = -1;
    while (--argc > 0 && **++argv == '-') {
        while((c = *++(*argv)))
            switch(c) {
                case 'n':
                    //printf("* %c *", c);
                    EXPECT = 1;
                    break;
                default:
                    printf("%s: unexpected token %c\n", name, c);
                    argc = -1;
                    break;
            }
    }
    //printf("%d*", argc);
    if (argc < 0) {
        printf("Usage: %s -<argument> <value>\n"
                "-n <value> compare atmost n characters\n", name);
        return 1;
    } else if (EXPECT && argc == 1 && (np = *argv)) {
        //printf("%s", np);
        number = atoi(np);
    }
    /*printf("%d\n", number);
    return 0;*/
    struct tnode *root;
    char word[MAXWORD];

    root = NULL;
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            root = addtree(root, word, number);
    treeprint(root);
    return 0;
}
