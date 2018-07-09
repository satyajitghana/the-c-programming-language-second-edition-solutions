#include <stdio.h>
#include "getnum.h"
#define log(d) printf(#d " : %d\n", d);

int main() {
    int num, r;
    if (r = getint(&num)) {
        log(num);
        log(r);
    }
    return 0;
}
