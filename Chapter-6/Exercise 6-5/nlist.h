#ifndef NLIST_H
#define NLIST_H

struct nlist {          /* table entry */
    struct nlist *next; /* next entry in the chain */
    char *name;         /* defined name */
    char *defn;         /* replacement text */
};

unsigned hash(char*);

struct nlist *lookup(char*);

struct nlist *install(char*, char*);

int undef(char*);

#endif
