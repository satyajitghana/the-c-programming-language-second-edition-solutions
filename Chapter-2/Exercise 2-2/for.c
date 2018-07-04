#include <stdio.h>
#define MAX 100

int main() {
    int c, lim = MAX, i = 0;
    char line[MAX];
    while (i < lim-1) {
        if ((c = getchar()) != '\n') {
            if (c != EOF)
                line[i++] = c;
            else break;
        }
        else {
            line[i++] = '\n';
            line[i] = '\0';
            break;
        }
    }
    printf("%s", line);
    return 0;
}
