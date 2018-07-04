#include <stdio.h>

// ctrl + d produces the EOF character, which will print 0 since the realtion becomes false
// and any other character will print 1m since the realtion is true
main() {
    printf("%d\n", getchar() != EOF);
}
