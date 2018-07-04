#include <stdio.h>

main() {
    float celsius, fahr;

    int start = 0;
    int end = 300;
    int step = 20;

    celsius = start;

    printf("%10s %10s\n", "celsius", "farenheit");
    while (celsius <= end) {
        fahr = ((9.0/5.0) * (celsius)) + 32.0;
        printf("%10.0f %10.2f\n", celsius, fahr);
        celsius += step;
    }
}
