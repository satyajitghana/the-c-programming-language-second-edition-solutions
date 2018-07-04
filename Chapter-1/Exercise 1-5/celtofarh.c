#include <stdio.h>

main() {
    printf("%10s %10s\n", "celsius", "farenheit");
    for (float celsius = 300; celsius >= 0 ; celsius -= 20) {
        printf("%10.0f %10.2f\n", celsius, (9.0*celsius/5.0) + 32.0);
    }
}
