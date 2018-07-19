#ifndef TREE_H
#define TREE_H

struct tnode {          /* the tree node: */
    char *word;             /* points to the text   */
    int count;              /* number of occurences */
    struct tnode *left;     /* left child           */
    struct tnode *right;    /* right child          */
};

struct tnode *addtree(struct tnode *, char *);

void treeprint(struct tnode *p);

struct tnode *talloc(void);

#endif
