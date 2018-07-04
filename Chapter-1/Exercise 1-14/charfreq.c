#include <stdio.h>
#define SIZE 256 // that's the total number of ascii characters

main() {
    int c, count[SIZE] = {};
    while ((c = getchar()) != EOF) {
        if (c != '\t' && c != '\b' && c != '\n' && c != ' ') ++count[c];
    }
    putchar('\n');
    for (int i = 0 ; i < SIZE ; i++) {
        if (count[i] != 0) {
            printf("%c : ", i);
            for (int j = 0 ; j < count[i] ; j++) putchar('#');
            putchar('\n');
        }
    }
}
