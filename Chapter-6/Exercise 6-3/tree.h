#ifndef TREE_H
#define TREE_H

#define MAXLNUMBERS 100

struct tnode {          /* the tree node: */
    char *word;                 /* points to the text   */
    int count;                  /* number of occurences */
    int lnum[MAXLNUMBERS];      /* list of line number on which it occurs */
    int lsize;                  /* number of lines wheresword occurs */
    struct tnode *left;         /* left child           */
    struct tnode *right;        /* right child          */
};

struct tnode *addtree(struct tnode *, char *, int);

void treeprint(struct tnode *p);

struct tnode *talloc(void);

int lsearch(int *, int, int);

#endif
