#include <stdio.h>
#include "getnum.h"
#define log(d) printf(#d " : %d\n", d);

int main() {
    int num;
    if (getint(&num))
        log(num);
    return 0;
}
