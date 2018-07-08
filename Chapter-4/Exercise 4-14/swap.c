#include<stdio.h>

/* tmp##x##y creates a unique kind of temp variable name, so tmp wouln't conflict with the variable names. */
#define swap(t, x, y) { \
t tmp ##x ##y = x;     \
x = y;                  \
y = tmp ##x ##y;        \
}

#define dprintf(x, y) {             \
printf("x : %g, y : %g\n", x, y);   \
}

int main() {
    double tmp = 5, b = 2;
    dprintf(tmp, b);
    swap(double, tmp, b);
    dprintf(tmp, b);
    return 0;
}
