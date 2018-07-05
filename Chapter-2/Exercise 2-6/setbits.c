#include <stdio.h>

int setbits(int x, int pos, int n, int y);

int main() {
     // let x be 10101011
    int x = 171;
    // let y be 11111111
    int y = 255;

    //let position be 3, and 3 bits to be copied
    int p = 3;
    int n = 3;

    // result must be 11111101
    printf("%d\n", setbits(x, p, n, y));

    return 0;
}

setbits(x, p, n, y) {
    // push n bits from pth position of x to the right and clear other bits
    int tmp1 = (x >> (p-n+1)) & ~(~0<<n);
    // erase the last n bits in y
    int tmp2 = y & (~0 << n);
    // now just OR the two together
    int res = tmp1 | tmp2;

    return res;
}
