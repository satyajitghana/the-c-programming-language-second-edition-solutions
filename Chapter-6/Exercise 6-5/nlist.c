#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "nlist.h"
#include "io.h"

#define HASHSIZE 101

static struct nlist *hashtab[HASHSIZE]; /* pointer table */

/* hash: form hash value for string s */
unsigned hash(char *s) {
    unsigned hashval;

    for (hashval = 0; *s != '\0' ; s++)
        hashval = *s + 31 * hashval;

    return hashval % HASHSIZE;
}

/* lookup: look for s in hashtab */
struct nlist *lookup(char *s) {
    struct nlist *np;

    for (np = hashtab[hash(s)] ; np != NULL ; np = np -> next)
        if (strcmp(s, np -> name) == 0)
            return np;  /* found */
    return NULL;        /* not found */
}

/* install: put(name, defn) in hashtab */
struct nlist *install(char* name, char* defn) {
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL) { /* not found */
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np -> name = _strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np -> next = hashtab[hashval];
        hashtab[hashval]  = np;
    } else /* that means its already there */
        free((void*) np -> defn); /* free previous defn */
    if ((np -> defn = _strdup(defn)) == NULL)
        return NULL;
    return np;
}

/* undef: removes a name from the hashtab */
int undef(char* name) {
    struct nlist *np;

    if ((np = lookup(name)) == NULL)
        return 1; /* the name was not found */

    struct nlist *prev_np = NULL;
    unsigned hashval = hash(name);
    for (np = hashtab[hashval] ; np != NULL; prev_np = np, np = np -> next) {
        if (strcmp(np -> name, name) == 0) { /* found the node with that name */
            if (prev_np == NULL) /* at the beginning ? */
                hashtab[hashval] = np -> next;
            else /* somewhere in the middle */
               prev_np -> next = np -> next;
            /* free the memory */
            free(np -> name);
            free(np -> defn);
            free(np);

            return 0;
        }
    }

    return 1; /* name not found */
}

