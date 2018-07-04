#include <stdio.h>
#include <limits.h>

int main() {
    printf("char : %d bits\n", CHAR_BIT);
    printf("\tunsigned max : %d\n", UCHAR_MAX);
    printf("\tsigned max   : %d\n", CHAR_MAX);
    printf("\tsigned mix   : %d\n", CHAR_MIN);
    putchar('\n');

    printf("short :\n");
    printf("\tunsigned max : %d\n", USHRT_MAX);
    printf("\tsigned max   : %d\n", SHRT_MAX);
    printf("\tsigned mix   : %d\n", SHRT_MIN);
    putchar('\n');

    printf("int : \n");
    printf("\tunsigned max : %u\n", UINT_MAX);
    printf("\tsigned max   : %d\n", INT_MAX);
    printf("\tsigned mix   : %d\n", INT_MIN);
    putchar('\n');

    printf("long : \n");
    printf("\tunsigned max : %lu\n", ULONG_MAX);
    printf("\tsigned max   : %ld\n", LONG_MAX);
    printf("\tsigned mix   : %ld\n", LONG_MIN);
    putchar('\n');

    printf("long long : \n");
    printf("\tunsigned max : %llu\n", ULLONG_MAX);
    printf("\tsigned max   : %lld\n", LLONG_MAX);
    printf("\tsigned mix   : %lld\n", LLONG_MIN);

    return 0;
}
