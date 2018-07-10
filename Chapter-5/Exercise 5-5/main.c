#include <stdio.h>
#include "my_string.h"

int main() {
    char s1[100] = "";
    char s2[100] = "shadow";
    char s3[100] = " leaf";
    char s4[] = "satyajit ghana";
    char s5[] = "satyajit";
    my_strncat(s2, s3, 3);
    printf("%s\n", s2);
    my_strncpy(s1, s2, 5);
    printf("%s\n", s1);
    printf("%d\n", my_strncmp(s4, s5, 8));
    return 0;
}
