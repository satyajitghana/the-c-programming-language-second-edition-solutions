#include <stdio.h>

int invert(int x, int pos, int n);

int main() {
     // let x be 10101011
    int x = 171;

    //let position be 3, and 3 bits to be inverted
    int p = 3;
    int n = 3;

    // result must be 10100101
    printf("%d\n", invert(x, p, n));

    return 0;
}

int invert(int x, int p, int n) {
    int MASK = (~0<<(p+1)) | ~(~0<<(p-n+1));
    int tmp1 = ~(x & ~(MASK));
    int tmp2 = (x & (MASK)) | ~MASK ;
    printf("%d %d %d\n", MASK, tmp1, tmp2);
    int res = tmp1 & tmp2;
    return res;
}
