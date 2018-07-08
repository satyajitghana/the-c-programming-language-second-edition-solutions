#include <stdio.h>
#include <string.h>

void reverse(char string[], int start_index, int end_index);

int main() {
    char str[] = "shadowleaf satyajit";
    reverse(str, 0, strlen(str)-1);
    printf("%s\n", str);
    return 0;
}

void reverse(char s[], int head, int tail) {
    char tmp = s[head];
    s[head] = s[tail];
    s[tail] = tmp;
    
    if (head < tail)
    reverse(s, ++head, --tail);
    //printf(" *%c|%c* ", s[head], s[tail]);
}
