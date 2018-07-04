#include <stdio.h>
#define SIZE 15 // assuming the maximum size of a word is 15 letters long
#define MAXHEIGHT 15 // assuming the maximum frequency of a word to be 15
//else use another loop to determine the maximum height

main() {
    int c, count[SIZE] = {}, tmp = 0;
    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\n' && c != '\t') ++tmp;
        else {
            ++count[tmp-1];
            tmp = 0;
        }
    }
    for (int m = 0 ; m < MAXHEIGHT ; m++) {
        for (int i = 0 ; i < SIZE ; i++) {
            if (count[i] != 0) {
                if (count[i] >= MAXHEIGHT - m) putchar('#');
                else putchar(' ');
            }
        }
        putchar('\n');
    }

    for (int i = 0 ; i < SIZE ; i++) {
        if (count[i] != 0) printf("%d", i+1);
    }
    putchar('\n');
}
