#include <stdio.h>
#define MAXLENGTH 100

void itoa(int number, char numstr[], int pos);

int main() {
    int num = -1230123;
    char numstr[MAXLENGTH];
    itoa(num, numstr, 0);
    printf("%s\n", numstr);
    return 0;
}
