#include <stdio.h>
#include "getnum.h"
#define log(d) printf(#d " : %g\n", d);

int main() {
    float num;
    int r;
    if (r = getfloat(&num)) {
        //r = getfloat(&num);
        log(num);
        printf("r : %d\n", r);
    }
    return 0;
}
