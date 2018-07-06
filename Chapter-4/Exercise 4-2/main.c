#include <stdio.h>
#include <string.h>
#define MAXLENGTH 1000

int _getline(char str[], int lim);
double atof(char str[]);

int main() {
    char line[MAXLENGTH];
    int len;
    while ((len = _getline(line, MAXLENGTH)) > 0) {
        printf("%.10f\n", atof(line));
    }
    return 0;
}
