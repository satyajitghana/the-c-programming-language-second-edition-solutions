#include <stdio.h>

int strrindex(char s[], char t[]) {
    int i, j, k, r = -1;

    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0 ; t[k] != '\0' && s[j] == t[k]; j++, k++) ;
        if (k > 0 && t[k] == '\0') r = i;
    }
    return r;
}
