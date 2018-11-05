#include <stdio.h>
#include "nlist.h"

int main() {
    install("satyajit", "ghana");

    struct nlist *search;
    if ((search = lookup("satyajit")) != NULL)
        printf("name : %s, defn : %s\n", search -> name, search -> defn);
    /* delete the name */
    if (undef("satyajit") == 0 ) {
        printf("deleted !");
        printf(" lookup : %d\n", lookup("satyajit"));
    }

    return 0;
}
