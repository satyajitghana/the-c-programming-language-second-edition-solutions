#include <stdio.h>
#include <string.h>
#define MAXLENGTH 1000

int _getline(char str[], int lim);
int strrindex(char str[], char t[]);

int main() {
    char str[MAXLENGTH], pattrn[MAXLENGTH] = "";
    int len;
    while ((len = _getline(str, MAXLENGTH)) > 0) {
        printf("Enter the pattern to search : ");
        _getline(pattrn, MAXLENGTH);
        pattrn[strlen(pattrn)-1] = '\0';
        int loc = strrindex(str, pattrn);
        if (loc != -1)
            printf("\nFound at : %d\n", loc);
        else printf("\nNot Found\n");
    }
    return 0;
}
