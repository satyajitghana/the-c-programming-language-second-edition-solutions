#include <stdio.h>

unsigned int rightrot(unsigned int x, int n);

int main() {
     // let x be 00000000000000000000000010101011
    unsigned int x = 171;
    int n = 4;

    // result must be 10110000000000000000000000001010
    printf("%u\n", rightrot(x, n));

    return 0;
}

unsigned int rightrot(unsigned int x, int n) {
    for (int i = 0 ; i < n ; i++) {
        if (x & 1 == 1) {
            //putchar('*');
            x = x >> 1;
            x = x | ~(~0U >> 1);
        } else {
            //putchar('_');
            x = x >> 1;
        }
    }
    return x;
}
