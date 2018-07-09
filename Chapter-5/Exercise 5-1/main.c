#include <stdio.h>
#define log(d) printf(#d " : %d\n", d);

int getint(int *);

int main() {
    int num;
    if (getint(&num))
        log(num);
    return 0;
}
