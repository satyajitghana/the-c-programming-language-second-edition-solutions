#include <stdio.h>

int bitcount(unsigned x);

int main() {
     // let x be 10101011
    unsigned x = 171;

    // result must be 5
    printf("%d\n", bitcount(x));

    return 0;
}

int bitcount(unsigned x) {
    int b = 0;
    while (x) {
        x &= (x-1);
        b++;
    }
    return b;
}
